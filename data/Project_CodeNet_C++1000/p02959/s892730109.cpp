#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rep2(i,n) for (int i = 1; i <= (n); i++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
using ll = long long;
template <class T>
using Grid = vector<vector<T>>;

int main(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    rep(i, n+1) cin >> a[i];
    vector<int> b(n);
    rep(i, n) cin >> b[i];
    ll count = 0;
    rep(i, n) {
        if (a[i] >= b[i]) {
            count += b[i];
        }
        else {
            count += a[i];
            b[i] -= a[i];
            count += min(b[i], a[i + 1]);
            a[i + 1] -= min(a[i + 1], b[i]);
        }
    }
    cout << count << endl;
}