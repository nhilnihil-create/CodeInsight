#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const lli mod = 1e9+7;
lli n, k;

int main(void){
    cin >> n >> k;
    vector<lli> s(n+2);
    rep(i, n+1) s[i+1] = s[i]+i+1;
    lli ans = 0;
    for(int i = k; i <= n+1; i++){
        lli t, p;
        t = s[i];
        p = s[n+1]-s[n+1-i];
        ans+=p-t+1;
        ans%=mod;
    }
    cout << ans << endl;
    return 0;
}
