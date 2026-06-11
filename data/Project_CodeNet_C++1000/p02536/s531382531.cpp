#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
const int INF = 1001001001;
using ll = long long;

int main(){
    int n,m;
    cin >> n >> m;
    dsu d(n);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        d.merge(a,b);
    }
    int cnt = d.groups().size();
    int ans = cnt -1;
    cout << ans << endl;
    return 0;
}