#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 300100;
int amt[N];
int amts[N];
using ii=long long;
ii sums[2][N];
int val[N];
int ind[N];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        amt[x]++;
    }
    for (int i = 1; i <= n; ++i) {
        amts[amt[i]]++;
    }
    for (int i = 1; i <= n; ++i) {
        sums[0][i]=sums[0][i-1]+amts[i]*i;
        sums[1][i]=sums[1][i-1]+amts[i];
    }
    for (int i = 1; i <= n; ++i) {
        val[i] = (sums[0][i] + 1ll * i * (sums[1][n] - sums[1][i])) / ((ii) i);
    }
    for (int i = n; i; --i) {
        int u = val[i];
        if (ind[u] == 0) {
            ind[u] = i;
        }
    }
    for (int i = n; i; --i) {
        ind[i - 1] = max(ind[i - 1], ind[i]);
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d\n", ind[i]);
    }
}
