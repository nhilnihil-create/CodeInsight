#include <iostream>
#include <vector>

using namespace std;

int n;
const int MAX_A = 1e6 + 5;
int cnt[MAX_A] = {};

int main() {
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);

        if (cnt[a[i]] != 0) {
            cnt[a[i]] = 2;
            continue;
        }
        for (int j = a[i]; j < MAX_A; j += a[i]) {
            cnt[j]++;
        }
    }
    int ans = 0;
    for (auto x : a) {
        if (cnt[x] == 1) ans++;
    }
    printf("%d\n", ans);

    return 0;
}
