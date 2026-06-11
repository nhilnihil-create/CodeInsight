//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

int main() {
    int n, k, s;
    cin >> n >> k >> s;
    rep(i, k) printf("%d ", s);
    rep(i, n-k) {
        if (s == 1e9) printf("1 ");
        else printf("%d ", s+1);
    }
    cout << endl;

    return 0;
}