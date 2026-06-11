#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;

int main() {
    int n, k, q, tmp;
    cin >> n >> k >> q;
    vector<int> a(n);
    int ini = k - q;
    rep(i, n) a[i] = ini;
    rep(i, q) {
        cin >> tmp;
        a[tmp - 1]++;
    }
    rep(i, n) {
        if (a[i] <= 0)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}