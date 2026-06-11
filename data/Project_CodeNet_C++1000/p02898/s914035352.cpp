#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    scanf("%d %d", &n, &k);
    int res = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (x >= k) res++;
    }
    printf("%d", res);
    
    return 0;
}
