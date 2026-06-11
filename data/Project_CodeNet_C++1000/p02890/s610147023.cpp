#include<cstdio>
#include<map>
using namespace std;

const int N_MAX = 3e5;
int n;
int cnt[N_MAX + 1], sum[N_MAX + 1], mul[N_MAX + 1], ans[N_MAX + 1];
map<int, int> m;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        m[a]++;
    }

    for (auto &i : m) cnt[i.second]++;
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + cnt[i];
        mul[i] = mul[i - 1] + cnt[i] * i;
    }
    for (int i = n; i >= 1; i--) {
        int a = sum[n] - sum[i - 1] + mul[i - 1] / i;
        for (int j = a; j >= 1 && ans[j] == 0; j--) ans[j] = i;
    }

    for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
    return 0;
}
