#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int main() {
    int n, m;
    cin >> n >> m;
    vector<bool> ac(n, false);
    vector<int> pe(n, 0);
    int p; string s;
    for (int i = 0; i < m; ++i) {
        cin >> p >> s;
        p--;
        if (s == "AC") ac[p] = true;
        else {
            if (!ac[p]) pe[p]++;
        }
    }

    int resac = 0;
    int respe = 0;
    for (int i = 0; i < n; ++i) {
        if (ac[i]) resac++;
        if (ac[i]) respe += pe[i];
    }
    cout << resac << " " << respe << endl;
}
