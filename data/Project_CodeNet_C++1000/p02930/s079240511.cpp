#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define endl "\n"
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

int n;
int a[510][510];

void dfs(int l, int r, int level) {
    if(l >= r - 1) {
        return;
    }
    int mid = (l + r) / 2;
    for(int i = l; i < mid; i++) {
        for(int j = mid; j < r; j++) {
            a[i][j] = a[j][i] = level;
        }
    }
    dfs(l, mid, level + 1);
    dfs(mid, r, level + 1);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    dfs(0, n, 1);
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}