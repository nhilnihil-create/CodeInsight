 #include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), c(n);
    rep(i, n) cin >> a[i];
    copy(a.begin(), a.end(), c.begin());
    sort(c.begin(), c.end(), greater<int>());

    rep(i, n) {
        if(a[i] == c[0]) {
            cout << c[1] << endl;
            continue;
        }
        cout << c[0] << endl;
    }
    return 0;
}