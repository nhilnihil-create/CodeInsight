#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back

const int N = 200005;
int a[N];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] += a[i-1];
        a[i] %= k;
    }
    map <int, int> mp;
    mp[0] = 1;
    mp[-k] = 1;
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        if (i - k >= 0) {
            mp[a[i-k]-i+k]--;
            mp[a[i-k]-i]--;
        }
        if (mp.count(a[i] - i)) {
            res += mp[a[i]-i];
        }
        /*
        if (mp.count(a[i] - i + k)) {
            res += mp[a[i]-i+k];
        }*/
        mp[a[i]-i]++;
        mp[a[i]-i-k]++;
    }
    printf("%lld", res);
    return 0;
}
