#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
 
#define rp(i, k, n) for (int i = k; i < n; i++)
using ll = long long;
using ld = double;

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;


int main() {
    int n, x, y; 
    cin >> n >> x >> y;
    x--; y--;
    vector<int> res(n);
    rp(i, 0, n) {
        rp(j, i+1, n) {
            int dis = min(j-i, abs(i-x) + abs(j-y) + 1);
            res.at(dis) ++;
        }
    }
    rp(i, 1, n) {
        cout << res[i] << endl;
    }
    return 0;
}
