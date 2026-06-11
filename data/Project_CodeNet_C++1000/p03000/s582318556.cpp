#include <bits/stdc++.h>
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) x.begin(),x.end()
using namespace std;


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n,x;
    cin >> n >> x;
    vector<int> l(n);
    vector<int> d(n);
    d[0]=0;
    int cnt=1;
    rep (i, n) cin >> l[i];
    for(int i=1; i<=n; ++i) {
        d[i]=d[i-1] + l[i-1];
        if (d[i] <= x) cnt++;
    }
    cout << cnt << endl;
    return 0;
}