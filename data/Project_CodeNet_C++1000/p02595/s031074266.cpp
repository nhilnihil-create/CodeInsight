#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll oo = 1e9 + 10;
const ll mod = 998244353,maxn = 110;
const double PI = acos(-1); 

int solve(vector<pll> &vs, int n, ll d){
    int ans = 0;
    for (int i=0; i<n; i++){
        ans += (d*d >= vs[i].ff*vs[i].ff + vs[i].ss*vs[i].ss);
    }
    return ans;
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, d;
    cin >> n >> d;

    vector<pll> vs(n);

    for (int i=0; i<n; i++){
        cin >> vs[i].ff >> vs[i].ss;
    }

    auto ans = solve(vs, n, d);

    cout << ans << endl;
    return 0; 
}