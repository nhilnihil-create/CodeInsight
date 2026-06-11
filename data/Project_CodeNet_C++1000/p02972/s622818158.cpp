#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> b(n);
    vector<int> ans;
    int m = 0;
    for (int i = n-1; i >= 0; --i) {
        if (a[i] == 1) {
            int s = 0;
            rep(j, n/(i+1)) {
                if (b[(i+1) * (j+1) - 1]) s++;
            }
            if (s % 2 == 0) {b[i] = 1; m++; ans.push_back(i+1);}
        }
        else {
            int s = 0;
            rep(j, n/(i+1)) {
                if (b[(i+1) * (j+1) - 1]) s++;
            }
            if (s % 2 == 1) {b[i] = 1; m++; ans.push_back(i+1);}
        }
    }
    cout << m << endl;
    if (m != 0) {
        rep(i, ans.size()-1) cout << ans[i] << " ";
        cout << ans[ans.size()-1] << endl;
    }
}