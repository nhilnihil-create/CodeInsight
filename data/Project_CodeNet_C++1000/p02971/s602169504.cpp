#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    rep(i, n) {
        scanf("%d", &a[i]);
    }

    vector<int> a_copy = a;
    sort(a.begin(), a.end());
    rep(i, n) {
        if (a_copy[i] != a[n-1]) {
            printf("%d\n", a[n-1]);
        } else {
            printf("%d\n", a[n-2]);
        }
    }
}