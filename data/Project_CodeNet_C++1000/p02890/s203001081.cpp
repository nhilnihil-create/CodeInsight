#include <iostream>
#include <cstring>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int c[n];
    memset(c, 0, sizeof(c));
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        c[--a]++;
    }

    int ccps[n+1], ccss[n+2];
    memset(ccps, 0, sizeof(ccps));
    memset(ccss, 0, sizeof(ccss));
    for (int i = 0; i < n; i++) {
        ccps[c[i]] += c[i];
        ccss[c[i]]++;
    }

    for (int i = 1; i <= n; i++) {
        ccps[i] += ccps[i-1];
    }
    for (int i = n; i >= 0; i--) {
        ccss[i] += ccss[i+1];
    }

    int j = n;
    for (int i = 1; i <= n; i++) {
        while (ccps[j] + 1ll * j * ccss[j+1] < 1ll * i * j) {
            j--;
        }
        cout << j << "\n";
    }

    return 0;
}
