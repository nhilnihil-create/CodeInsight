#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i, n) cin >> v[i];
    sort(all(v));
    double price = (double) v[0];
    for (int i = 1; i < n; i++) {
        price = (price + v[i]) / 2.0;
    }
    cout << price << "\n";
}