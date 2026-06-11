#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int n;
    scanf("%d", &n);
    vector<int> h(n);
    rep(i, n) {
        scanf("%d", &h[i]);
    }
    bool yes = true;
    rep(i, n) {
        if (i == 0) {
            h[i]--;
            continue;
        }
        if (h[i] < h[i-1]) {
            yes = false;
            break;
        } else if (h[i] > h[i-1]) {
            h[i]--;
        }
    }
    if (yes) printf("Yes\n");
    else printf("No\n");
}