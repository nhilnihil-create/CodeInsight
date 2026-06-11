#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main(){
    string s; cin>>s;
    ll n=s.size();
    ll res=0;
    ll i=0;
    ll before=2;
    while(i<n){
        if(before==1 && s[i]==s[i-1]){
            if(i==n-1) break;
            res++; i+=2; before=2;
        }else if(before==1 && s[i]!=s[i-1]){
            res++; i++;
        }else if(before==2){
            res++; i++; before=1;
        }
    }
    cout<<res<<endl;
    return 0;
}