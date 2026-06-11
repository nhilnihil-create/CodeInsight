#include<cstdio>
#include<vector>
using namespace std;
typedef pair<int, int> P;

int k, q, d[5000];
int a[5000], b[5000], c[5000];

int main() {
    scanf("%d %d", &k, &q);
    for (int i = 0; i < k; i++) scanf("%d", &d[i]);
    for (int i = 0; i < q; i++) scanf("%d %d %d", &a[i], &b[i], &c[i]);
    for (int j = 0; j < q; j++) {
        int n = a[j], x = b[j] % c[j], m = c[j];
        int y = 0, cnt = 0;
        for (int i = 0; i < k - 1; i++) {
            if (y + d[i] % m >= m || d[i] % m == 0) cnt++;
            y = (y + d[i]) % m;
        }
        int ans = 0;
        if (y + d[k - 1] % m >= m || d[k - 1] % m == 0) {
            cnt++;
            ans = -1;
        }
        int e = (y + d[k - 1]) % m;
        ans += n / k * cnt + (static_cast<long>(e) * (n / k - 1) + x + y) / m;
        y = (static_cast<long>(e) * (n / k - 1) + x + y) % m;
        if (n % k > 0 && (y + d[k - 1] % m >= m || d[k - 1] % m == 0)) ans++;
        y = (y + d[k - 1]) % m;
        for (int i = 0; i < n % k - 1; i++) {
            if (y + d[i] % m >= m || d[i] % m == 0) ans++;
            y = (y + d[i]) % m;
        }
        ans = n - 1 - ans;
        printf("%d\n", ans);
    }
    return 0;
} 
