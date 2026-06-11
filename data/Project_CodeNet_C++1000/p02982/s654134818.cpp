#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

bool isok(int n) {
    for (int i = 0; i < 200; ++i) {
        if (n == i * i) return true;
    }
    return false;
}

int main(){
    int n, d;
    cin >> n >> d;
    vector<vector<int>> point(n, vector<int>(d));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
            cin >> point[i][j];
        }
    }

    int res = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = i+1; j < n; ++j) {
            int dis = 0;
            for (int k = 0; k < d; ++k) {
                dis += (point[i][k] - point[j][k]) * (point[i][k] - point[j][k]);
            }
            if (isok(dis)) res++;
        }
    }
    cout << res << endl;
}