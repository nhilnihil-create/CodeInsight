#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
struct rgb
{
    int R=0;
    int G=0;
    int B=0;
};

int main(){
    ll n,ans=0;
    string s;
    cin>>n>>s;
    vector<rgb> tup(n+1);
    for(int i=n;i>=0;i--){
        switch (s[i])
        {
            case 'R':
            tup[i].R=tup[i+1].R+1;
            tup[i].G=tup[i+1].G;
            tup[i].B=tup[i+1].B;
            break;
            case 'G':
            tup[i].R=tup[i+1].R;
            tup[i].G=tup[i+1].G+1;
            tup[i].B=tup[i+1].B;
            break;
            case 'B':
            tup[i].R=tup[i+1].R;
            tup[i].G=tup[i+1].G;
            tup[i].B=tup[i+1].B+1;
            break;
            default:
            break;;

        }
    }
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            if(s[i]==s[j])continue;
            if(s[i]=='R'){
                if(s[j]=='G') {
                    ans+=tup[j+1].B;
                    if(j+j-i<n)
                    if(s[j+j-i]=='B') ans--;
                }
                if(s[j]=='B') {
                    ans+=tup[j+1].G;
                    if(j+j-i<n)
                    if(s[j+j-i]=='G') ans--;
                }
            }

            else if(s[i]=='G'){
                if(s[j]=='R') {
                    ans+=tup[j+1].B;
                    if(j+j-i<n)
                    if(s[j+j-i]=='B') ans--;
                }
                if(s[j]=='B') {
                    ans+=tup[j+1].R;
                    if(j+j-i<n)
                    if(s[j+j-i]=='R') ans--;
                }
            }

            else if(s[i]=='B'){
                if(s[j]=='R') {
                    ans+=tup[j+1].G;
                    if(j+j-i<n)
                    if(s[j+j-i]=='G') ans--;
                }
                if(s[j]=='G') {
                    ans+=tup[j+1].R;
                    if(j+j-i<n)
                    if(s[j+j-i]=='R') ans--;
                }
            }
        }
    }
    cout<<ans<<endl;
}
