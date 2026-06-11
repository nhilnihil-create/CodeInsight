#include <bits/stdc++.h>
 
using namespace std;

int num[300010], mx[300010], frac[300010]; 
int ok[300010], ans[300010];
int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        num[x]++;
    }
    for (int i = 1; i <= n; i++) {
        mx[0]++;
        mx[num[i] + 1]--;
        frac[num[i] + 1] += num[i];
    }
    for (int i = 1; i <= n; i++) {
        mx[i] += mx[i - 1];
        frac[i] += frac[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        int j = mx[i] * i + frac[i];
        ok[j / i] = i;
    }
    for (int i = n; i >= 1; i--) {
        ans[i] = max(ans[i + 1], ok[i]);
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
}