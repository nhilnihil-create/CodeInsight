#include <iostream>
#include <algorithm>
using namespace std;
int cnt[300005] = {0};
int pre[300005];

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int n;
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        cnt[tmp]++;
    }
    sort(cnt + 1, cnt + n + 1, cmp);
    pre[0] = 0;
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + cnt[i];
    }
    cout << n << endl;
    for (int i = 2; i <= n; i++) {
        if (cnt[i] == 0) {
            printf("0\n");
        } else {
            int x = n / i;
            int lft = 1;
            int pos = lower_bound(cnt + 1, cnt + n + 1, x, greater<int>()) - cnt;
            while (pos != lft) {
                lft = pos;
                x = (n - pre[pos - 1]) / (i - lft + 1);
                pos = lower_bound(cnt + 1, cnt + n + 1, x, greater<int>()) - cnt;
            }
            printf("%d\n", x);
        }
    }
}

