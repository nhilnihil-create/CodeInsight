#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
ll factorial(int i) {       //階乗
    if (i == 0) return 1;
    return (factorial(i - 1)) * i;
}
 
int main() {
    int n;
    cin >> n;
    vector<int> a(n - 1);
    int ans[210000];
    rep(i, n - 1) {
        cin >> a[i];
        ans[a[i]]++;
    }
    rep1(i, n) cout << ans[i] << "\n";
}