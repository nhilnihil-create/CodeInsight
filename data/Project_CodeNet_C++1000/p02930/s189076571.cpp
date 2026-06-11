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

int paint(int u, int v) {
    int diff = abs(u - v);
    for(int i = 0; i < 10; i++) {
        if(diff & (1 << i)) {
            return (i + 1);
        }
    }
    return 1 << 10;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            cout << paint(i, j) << ' ';
        }
        cout << endl;
    }
}