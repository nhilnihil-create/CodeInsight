#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define rep(i, a, n) for (int i = a; i < n; ++i)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    int cnt = 0;
    for (int i = 0; i < n; i += 2) {
        if (a[i] % 2 == 1) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
