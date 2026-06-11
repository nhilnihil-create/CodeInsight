#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    vector<vector<int>> road(n);
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        a--; b--;
        road[a].push_back(b);
        road[b].push_back(a);
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
        bool flag = true;
        for (int j = 0; j < road[i].size(); ++j) {
            if (h[i] <= h[road[i][j]]){
                flag = false;
                break;
            }
        }
        if (flag) res++;
    }
    cout << res << endl;
}