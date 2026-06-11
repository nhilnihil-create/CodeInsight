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

#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)

using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<ll> c(n, 0);
    vector<ll> d(n+1, 0);
    for (int i = 0; i < n; i++)
    {
        int a; cin >> a; a--;
        c[a]++;
        d[c[a]]++;
    }

    vector<ll> S(n+1, 0), S2(n+1, 0);
    for (int i = 1; i < n+1; i++)
    {
       S[i] = S[i-1] + d[i], S2[i] = S[i] / i;
    }
    

    ll x = n;
    for (ll k = 1; k <= n; k++)
    {
        while( x > 0 && k > S2[x]) --x;
        cout << x << endl;
    }
    
    

}