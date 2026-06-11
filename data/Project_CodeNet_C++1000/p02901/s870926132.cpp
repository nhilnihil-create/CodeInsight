#include <iostream>
#include <cstring>
using namespace std;
const int inf = 1e9;
struct key{
    int cost;
    int box;
} k[1005];
int n;
int cs[1 << 12];

int main() {
    int m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        k[i].box = 0;
    }
    int mx = (1 << n) - 1;
    for (int i = 1; i <= mx; i++) {
        cs[i] = inf;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        k[i].cost = a;
        int tmp;
        for (int j = 0; j < b; j++) {
            scanf("%d", &tmp);
            k[i].box += 1 << (tmp - 1);
        }
        cs[k[i].box] = min(cs[k[i].box], a);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= mx; j++) {
            int uni = k[i].box | j;
            if (cs[j] != inf && uni != j) {
                cs[uni] = min(cs[uni], cs[j] + k[i].cost);
            }
        }
    }
    if (cs[mx] != inf) cout << cs[mx];
    else cout << -1;
}

