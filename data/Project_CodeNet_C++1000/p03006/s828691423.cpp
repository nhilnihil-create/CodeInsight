#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<unordered_map>
#include<set>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define Pint pair<int, int>
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    int N; cin >> N;
    int x[N], y[N];
    rep(i, N) {
        cin >> x[i] >> y[i];
    }
    map<Pint, int>m;
    int maxv = 0;
    rep(i, N) {
        rng(j, i + 1, N) {
            m[mp(x[j] - x[i], y[j] - y[i])]++;
            m[mp(x[i] - x[j], y[i] - y[j])]++;
            maxv = max(maxv, m[mp(x[j] - x[i], y[j] - y[i])]);
            maxv = max(maxv, m[mp(x[i] - x[j], y[i] - y[j])]);
        }
    }
    cout << N - maxv << endl;
}
