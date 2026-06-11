#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using ll=long long;
using namespace std;
int main(){
    int n;
    cin>>n;
    ll ans=0;
    for(int a=1;a<=n;a++){
        ans+=(n-1)/a;
    }
    cout<<ans<<endl;
 }

