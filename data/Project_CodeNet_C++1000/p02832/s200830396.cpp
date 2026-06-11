#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back

int main() {
    int n;
    scanf("%d", &n);
    int res = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (x == res + 1) {
            res++;
        }
    }
    if (res == 0) printf("-1");
    else printf("%d", n - res);
    return 0;
}
