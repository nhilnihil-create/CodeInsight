#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(q);
    rep(i, q) {
        cin >> a[i];
    }
    vector<int> st(n, k - q);
    rep(i, q)  {
        st[a[i] - 1]++;
    }
    rep(i, n) {
        if(st[i] > 0) {
            cout << "Yes" << "\n";
        }
        if(st[i] <= 0) {
            cout << "No" << "\n";
        }
    }

    return 0;
}
