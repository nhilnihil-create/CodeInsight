#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
#define all(a) a.begin(), a.end()
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;
using P  = pair<int,int>;
const int INF = 1001001001;
const int MOD = 1000000007;
const int NMAX = 2000;



int main(){
    int n;
    cin >> n;
    
    set<ll> plus, minus;
    
    rep(i,n){
        ll x, y;
        cin >> x >> y;
        plus.insert(x+y);
        minus.insert(x-y);
    }
    
    ll ans = *plus.rbegin() - *plus.begin();
    ans = max(ans, *minus.rbegin() - *minus.begin());
    cout << ans << endl;
    return 0;
}