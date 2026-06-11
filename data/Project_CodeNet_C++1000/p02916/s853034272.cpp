#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n-1);
    rep(i, n) cin >> a[i];
    rep(i, n) a[i]--;
    rep(i, n) cin >> b[i];
    rep(i, n-1) cin >> c[i];
    int sum = 0;
    rep(i, n-1) {
        sum += b.at(a.at(i));
        if (a[i] + 1 == a[i+1]) {
            sum += c.at(a.at(i));
        }
    }
    sum += b.at(a.at(n-1));
    cout << sum << endl;
}