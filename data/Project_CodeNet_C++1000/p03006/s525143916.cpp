#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli n;

lli posmod(lli x, lli mod){
    if(x >= 0) return x%mod;
    else return (x+mod)%mod;
}

int main(void){
    cin >> n;
    vector<lli> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    lli ans = n;
    rep(i, n){
        rep(j, n){
            if(j == i) continue;
            lli p = x[i]-x[j];
            lli q = y[i]-y[j];
            lli s = 0;
            rep(u, n){
                rep(v, n){
                    lli dx = x[u]-x[v];
                    lli dy = y[u]-y[v];
                    if(dx == p && dy == q) s++;
                }
            }
            ans = min(ans, n-s);
        }
    }
    cout << ans << endl;
    return 0;
}
