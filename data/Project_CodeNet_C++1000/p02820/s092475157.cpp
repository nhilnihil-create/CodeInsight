#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
int main(){
    int n,k;
    int r,s,p;
    ll ans=0;
    string str;
    cin>>n>>k>>r>>s>>p>>str;
    rep(i,n){
        switch (str[i]){
        case 'r':
            if(i-k>=0&&str[i-k]=='r') {
                str[i]='a';
                break;
                }
            ans+=p;
            break;
        case 's':
            if(i-k>=0&&str[i-k]=='s') {
                str[i]='a';
                break;
                }
            ans+=r;
            break;
        case 'p':
            if(i-k>=0&&str[i-k]=='p') {
                str[i]='a';
                break;
                }
            ans+=s;
            break;
        }
        
    }
    cout<<ans<<endl;
}
