#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define rREP(i,m,n) for(ll i = (m); i >= (n); i--)
#define ALL(c) (c).begin(), (c).end()
#define print(x) cout << (x) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    ll ary[n];
    rep(i,n) cin >> ary[i];

    ll ruiseki[n+1];
    ruiseki[0] = 0;
    rep(i,n)
    {
        ruiseki[i+1] = ruiseki[i] + ary[i] * 2;
    }

    ll mid = ruiseki[n]/2;
    auto itr = lower_bound(ruiseki, ruiseki+(n+1), mid);
    // cout << abs(*itr-mid) << endl;
    cout << min(abs(*itr-mid), abs(*(itr-1)-mid)) << endl;

    
    
}


