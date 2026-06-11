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

const ll MOD = 998244353;
const ll inf = 1e18;

int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    ll n, m;
    cin >> n >> m;
    vector<P> p(n);
    ll a, b;
    REP(i, n) {
        cin >> a >> b;
        p[i] = {a, b};
    }
    VSORT(p);

    // 期限がカツい日にできる仕事は限定的なので後ろ側からどの仕事をいれたら良いか考える
    // que : その日入れられる仕事の報酬リスト
    // p を a の昇順で並べて b を que に入れていく
    // 期限を巻き戻すほど入れられる仕事が増える
    priority_queue<ll> que;
    ll res = 0, d = m, id = 0;
    REPR(d, m) {
        while (id < n && d + p[id].first <= m) {
            que.push(p[id].second);
            id++;
        }
        if (!que.empty()) {
            res += que.top();
            que.pop();
        }
    }
    cout << res << endl;
    return 0;
}