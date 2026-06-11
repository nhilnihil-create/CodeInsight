#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) x.begin(),x.end()
using namespace std;

using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n,k;
    cin >> n >> k;
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    sort(ALL(p));
    ll sum=0;
    rep(i, k) sum+=p[i];
    cout << sum << endl;
    return 0;
}