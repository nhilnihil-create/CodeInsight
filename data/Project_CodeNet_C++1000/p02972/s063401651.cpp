#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define all(x) x.begin(), x.end()
using ll = long long;
using pii = pair<int, int>;
const int mod = 1e9+7;

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> b(n+1);
    vector<int> ans;
    for (int i = n; i >= 1; i--) {
        int sum = 0;
        for (int j = i; j <= n; j += i) {
            sum += b[j];
        }
        if (sum % 2 != a[i]) {
            b[i]++;
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
}