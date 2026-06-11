#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const int INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    ll N, D, A;//N : monsterNum,D: attackRange,A: Damage
    cin >> N >> D >> A;
    vector<P> monster(N);
    vector<ll>X(N), H(N);
    vector<ll> damage(N, 0);
    rep(i, N) {
        cin >> X[i] >> H[i];
        monster[i] = mp(X[i], H[i]);
    }
    sort(monster.begin(), monster.end());
    sort(X.begin(), X.end());
    ll ans = 0;
    rep(i, N) {
        if(damage[i] < monster[i].second) {
            ans += ll((monster[i].second - damage[i] - 1) / A + 1);
            ll dmg = ll((monster[i].second - damage[i] - 1) / A + 1) * A;
            damage[i] += dmg;
            damage[(upper_bound(all(X), 2 * D + monster[i].first)) - X.begin()] -= dmg;
        }
        damage[i + 1] += damage[i];
    }
    cout << ans << endl;
}
