#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
 
int main(){
    string s;cin>>s;
    int si=s.size();
    vector<int> v(si,0);
    int a=0;
    int b=0;
    s+='R';
    rep(i,si){
        if(s[i]=='R'&&s[i+1]=='L'){
            a=i;
        }
        else if(s[i]=='L'&&s[i+1]=='R'){
            if((a+1-b)%2){
            v[a]=(i+1-b+1)/2;
            v[a+1]=(i+1-b)/2;
            }
            else {
            v[a]=(i+1-b)/2;
            v[a+1]=(i+1-b+1)/2;
            }
            b=i+1;
        }
    }
    rep(i,si){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
