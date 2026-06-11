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
    int a, b, m;
    int sa[100001]; INITA(sa, 0, 100001, 0);
    int sb[100001]; INITA(sb, 0, 100001, 0);
    cin >> a >> b >> m;

    int mina = 100001;
    int minb = 100001;
    FOR(i, 1, a) { cin >> sa[i]; mina = min(mina, sa[i]);}
    FOR(i, 1, b) { cin >> sb[i]; minb = min(minb, sb[i]);}

    int res = mina + minb;
    REP(i, m) {
        int x, y, c;
        cin >> x >> y >> c;
        res = min(res, sa[x] + sb[y] - c);
    }
    cout << res << endl;
    return 0;
}