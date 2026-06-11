#include <bits/stdc++.h>
#define repp(i,l,r)for(long long i=(l);i<(r);i++)
#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define per(i,n) for (long long i = (n); i >= 0; --i)
const int INF = 2147483647;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//ミョ(-ω- ?)
int main() {
    ll n;
    cin >> n;
    vector<ll> a(n,0);
    ll sum = 0;
    vector<ll> res(n,0);
    rep(i,n){
        cin >> a[i];
        sum += a[i];
    }
    res[0] = sum;
    for(ll i = 1;i < n;i += 2)res[0] -= (2*a[i]);
    repp(i,1,n)res[i] = 2*a[i-1] - res[i-1];
    rep(i,n){
        cout << res[i];
        if(i != n-1)cout << " ";
    }
    cout << "\n";
    return 0;
}