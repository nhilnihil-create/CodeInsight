#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <sstream>
#include <cstring>
#include <cctype>
#include <set>
#include <queue>
#include <algorithm>

typedef long long ll;

using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 15;
const int MOD = 10000;

struct BOOK{
    int price;
    int a[MAXN];
}book[MAXN];
int b[MAXN];

int main()
{
    int n, m, x, price, level, ans = INF, res = 0;
    bool flag;
    scanf("%d %d %d", &n, &m, &x);

    for (int i = 0; i < n; i ++ ) {
        scanf("%d", &book[i].price);
        for (int j = 0; j < m; j ++ ) {
            scanf("%d", &book[i].a[j]);
        }
    }

    for (int i = 1; i < (1 << n); i ++ ) {
        res = 0;//统计每种情况所有书的总价格
        memset(b, 0, sizeof(b));
        for (int j = 0; j < n; j ++ ) {
            if ( i >> j & 1 ) {
                res += book[j].price;
                for (int k = 0; k < m; k ++ ) {
                    b[k] += book[j].a[k];
                }
            }
        }
        flag = true;
        for (int k = 0; k < m; k ++ ) {
            if ( b[k] < x ) {
                flag = false;
                break;
            }
        }

        if ( flag ) ans = min(ans, res);
    } 

    printf("%d", ans == INF?-1:ans);
    return 0;
}