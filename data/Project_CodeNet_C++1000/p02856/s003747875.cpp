#include <bits/stdc++.h>

#define FOR(i, l, r) for(ll i = l; i < r; i++)
#define rep(i, N) FOR(i, 0, N)

#define MOD 1000000007
#define INF 1000000000

using ll = long long int;
using namespace std;

typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;



int main() {
    int M; cin >> M;
    vector<ll> d(M), c(M);
    rep(i,M) cin >> d[i] >> c[i];

    ll ans = 0;
    rep(i,M) ans += c[i];
    ans--;

    ll sum = 0;
    rep(i,M){
        sum += (d[i]*c[i]);
    } 
    ans += (sum-1)/9;
    
    cout << ans << endl;
    return 0;
}
