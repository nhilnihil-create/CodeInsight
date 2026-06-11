#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) x.begin(),x.end()
using namespace std;

using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> b(n);
    rep(i, n) b[a[i] - 1] = i + 1;
    rep(i, n) cout << b[i] << endl;
    return 0;
}