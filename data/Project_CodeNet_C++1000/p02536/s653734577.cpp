#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using namespace atcoder;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;


int main(){
    int n, m;
    cin >> n >> m;
    dsu tree(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--, b--;
        tree.merge(a, b);
    }
    vector<vector<int>> v = tree.groups();
    cout << v.size() - 1 << endl;

    return 0;
}
