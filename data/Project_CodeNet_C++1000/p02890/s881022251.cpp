#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int N = 300010;
int a[N], t[N], c[N];

int main()
{
    register int n;
    scanf("%d", &n);
    for (register int i = 1, x; i <= n; ++i) {
        scanf("%d", &x);
        a[x]++;
    }
    for (register int i = 1; i <= n; ++i) {
        t[a[i]]++;
    }
    for (register int i = 1; i <= n; ++i) {
        c[i] = c[i - 1] + t[i] * i;
        t[i] += t[i - 1];
    }
    register int ans = n;
    for (register int i = 1; i <= n; ++i) {
        while(((t[n] - t[ans]) * ans + c[ans]) / i < ans) {
            --ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}