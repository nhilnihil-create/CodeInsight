#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll n,k;cin>>n>>k;
    string s;cin>>s;
    ll buf=1;
    char tmp=s[0];
    rep(i,n){
        if(tmp!=s[i]){
            buf++;
            tmp=s[i];
        }
    }
    buf-=k*2;
    if(buf<0)buf=0;
    if(buf==0){
        cout<<n-1<<endl;
        return 0;
    }else{
        cout<<n-buf<<endl;
        return 0;
    }
}