#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
 
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;

template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll mod = 1e9 + 7;
const ll inf = 1e18;

int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    ll n;
    cin >> n;

    // 1
    // 11, 12
    // 111, 112, *113*, 121, 122, 123

    // mem[length] : set of pair<res, last number>
    vector<vector<pair<vll, ll>>> mem(11);
    vll e = {1};
    mem[0].push_back({e, 1});
    REP(i, 9) {
        for (auto pre : mem[i]) {
            for (ll j = 1; j <= pre.second + 1; j++) {
                vll nxt = pre.first;
                nxt.push_back(j);
                mem[i + 1].push_back({nxt, max(pre.second, j)});
            }
        }
    }
    for (auto res : mem[n - 1]) {
        REP(i, n) {
            cout << char('a' + res.first[i] - 1);
        }
        cout << endl;
    }
    return 0;
}