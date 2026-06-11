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
    int N; cin >> N;
    vi A(N);
    rep(i,N) cin >> A[i];

    ll ans = 1;
    vi cnt(N+1, 0);
    cnt[0] = 3;

    rep(i, N){
        ans *= (cnt[A[i]] - cnt[A[i]+1]);
        ans %= MOD;
        cnt[A[i]+1]++;
    }

    cout << ans << endl;
    return 0;
}
