#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;

int n;
int a[Maxn];
int res[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int ind; scanf("%d", &ind); ind--;
        a[ind]++;
    }
    sort(a, a + n);
    int pos = 0;
    for (int i = 0; i < n; i++) {
        res[i] = a[i];
        if (i + 1 < n)
            while (a[i] > 0) {
                if (pos <= i) {
                    pos = i + 1;
                    while (pos + 1 < n && a[pos] == a[pos + 1]) pos++;
                }
                a[i]--; a[pos]++; pos--;
            }
    }
    for (int i = n - 1; i >= 0; i--)
        printf("%d\n", res[i]);
    return 0;
}
