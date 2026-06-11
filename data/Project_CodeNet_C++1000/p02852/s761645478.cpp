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

int n, m;
string s;
vector<int> res;

int main(){
    cin >> n >> m;
    cin >> s;
    int now = n;
    while (1) {
        bool flag = true;
        if (now <= m) {
            res.push_back(now);
            break;
        }
        for (int i = m; i > 0; --i) {
            if (s[now - i] == '1') continue;
            now -= i;
            res.push_back(i);
            flag = false;
            break;
        }
        if (flag) {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int i = res.size() - 1; i >= 0; --i) {
        cout << res[i] << " ";
    }
    cout << endl;
}