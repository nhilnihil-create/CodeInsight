#include <bits/stdc++.h>
using namespace std;

typedef double dbl;
typedef long long ll;
const int N = 200001;
int a[N];

int main(void) {
    int n, k; scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    
    dbl l = 0, r = 1145141919;
    for (int i = 1; i <= 100; ++i) {
        dbl m = (l + r) / 2;
        ll cnt = 0;
        for (int j = 1; j <= n; ++j)
            cnt += round(ceil(a[j] / m)) - 1;
        if (cnt > k)
            l = m;
        else
            r = m;
    }
    printf("%d\n", (int)ceil(r));

    return 0;
}