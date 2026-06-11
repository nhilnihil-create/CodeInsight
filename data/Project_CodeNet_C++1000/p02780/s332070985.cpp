#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define fi first
#define se second
#define pb push_back

const int N = 200005;
int a[N];

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    scanf("%d %d", &n, &k);
    ld res = 0, hold = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        hold += (ld)(a[i] + 1) / 2;
        if (i >= k - 1) {
            res = max(res, hold);
            hold -= (ld)(a[i-k+1] + 1) / 2;
        }
    }
    printf("%.12Lf", res);
    return 0;
}
