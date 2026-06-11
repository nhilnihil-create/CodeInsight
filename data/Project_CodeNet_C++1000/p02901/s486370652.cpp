#include <bits/stdc++.h>
using namespace std;

#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;

vector<int> cost(1e4, 1e9);

int main() {
    int n, m;
    cin >> n >> m;
    cost[0] = 0;
    rp(i, 0, m) {
        int a, b;
        scanf("%d%d", &a, &b);
        int key = 0;
        rp(i, 0, b) {
            int c; scanf("%d", &c);
            c--;
            key += (1<<c);
        }
        rp(j, 0, (1<<n)) {
            chmin(cost[j|key], a+cost[j]);
        } 
    }
    int res = cost[(1<<n) - 1];
    if(res == 1e9) cout << -1 << endl;
    else cout << cost[(1<<n) - 1] << endl;
    return 0;
}