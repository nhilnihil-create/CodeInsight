#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define D()
#define INF 1000000000000
#define MOD 10000007
#define MAXR 100000
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define INITA(a,i,j,v) for(ll k=i;k<=j;k++){a[k]=v;}
int main() {
    ll n; cin >> n;
    vector<ll> a(n+1, 0);
    REP(i, n) {
        cin >> a[i+1];
    }

    vector<ll> res(n+1, 0);
    ll num = 0;
    FORD(i, n, 1) {
        if (i * 2 > n) {
            res[i] = a[i];
        } else {
            ll tot = 0;
            for (ll j=i+i; j<=n; j+=i) {
                if (res[j] == 1) {
                    tot += res[j];
                }
            }
            if (tot % 2 != a[i]) {
                res[i] = 1;
            } else {
                res[i] = 0;
            }
        }
    }
    vector<ll> ans;
    FOR(i, 1, res.size()-1) {
        if (res[i] == 1) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    REP(i, ans.size()) {
        cout << ans[i] << endl;
    }
    return 0;
}