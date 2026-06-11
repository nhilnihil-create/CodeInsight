#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using V = vector<int>;

int main(int argc, char const *argv[])
{
    int n, k; cin >> n >> k;
    int p[1010];
    rep(i,n) cin >> p[i];
    sort(p,p+n);
    int ans = 0;
    rep(i,k) ans += p[i];
    cout << ans << endl;
    return 0;
}
