#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<set>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    int N; cin >> N;
    int A[N];
    vector<ll>cnt(N + 1, 0);
    cnt[0] = 3;
    ll ans = 1;
    rep(i, N) {
        cin >> A[i];
        ans = ans * cnt[A[i]] % MOD;
        cnt[A[i]]--;
        cnt[A[i] + 1]++;
    }
    cout << ans << endl;
}
