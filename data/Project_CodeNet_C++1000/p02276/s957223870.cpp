#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;

int partition(vector<int> &a, int p, int r) {
    int bdry = 0;
    rep(i, a.size()) {
        if(a[i] <= a[r]) {
            swap(a[i], a[bdry]);
            bdry++;
        }
    }
    return bdry - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int idx = partition(a, 0, n - 1);

    rep(i, n) {
        if(i == idx) printf("[");
        printf("%d", a[i]);
        if(i == idx) printf("]");
        printf(i == n - 1 ? "\n" : " ");
    }

    return 0;
}
