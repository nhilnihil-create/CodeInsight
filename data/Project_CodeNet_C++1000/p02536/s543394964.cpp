#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define ll long long

#define rep(i,n) for(int i = 0; i < (n); i++)

int main () {
    int n, m, a, b;
    cin >> n >> m;
    dsu d(n);
    rep(i, m) {
        cin >> a >> b;
        a--;
        b--;
        d.merge(a,b);
    }
    int cnt = d.groups().size();
    int ans = cnt - 1;
    cout << ans << endl;
    return 0;
}
