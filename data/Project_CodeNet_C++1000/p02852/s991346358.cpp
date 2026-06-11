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
    string s;
    cin >> s;
    ll mem = 0, b = 0, w = 0;
    vll a(n + 1);
    REP(i, n + 1) {
        a[i] = int(s[i] - '0');
        if (a[i] == 1) b++;
        else {
            chmax(mem, b);
            b = 0;
        }
    }

    if (mem >= m) {
        cout << -1 << endl;
        return 0;
    }
    reverse(ALL(a));
    vll res;
    ll cur = 0;
    
    while (cur != n) {
        ll dice = m;
        while (1) {
            chmin(dice, n - cur);
            if (a[cur + dice] == 0) {
                cur += dice;
                res.push_back(dice);
                break;
            }
            dice--;
        }
    }
    reverse(ALL(res));
    for (auto x : res) {
        cout << x << " ";
    }
    return 0;
}