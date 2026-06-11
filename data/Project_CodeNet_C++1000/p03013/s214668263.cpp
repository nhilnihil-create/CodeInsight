//
//AtCoder Beginner Contest 129
//C - Typical Stairs
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <queue>
#include <map>
#include <set>
#include <tuple>
#include <functional>
#include <cassert>

using namespace std;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end()
#define RALL(x) (x).rbegin(),(x).rend()
#define SIZE(x) (int)(x).size()
#define SIZEL(x) (ll)(x).size()
#define MSG(a) cout << #a << " " << a << endl;

using ll = long long;
using ld = long double;

const double PI = 3.14159265358979323846;
const int MOD = 1000000007;

ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }            //最小公倍数

int main()
{
    int n,m;
    cin >> n >> m;

    vector<int> bk(n+1, 0);
    REP(i, m) {
        int a;
        cin >> a;
        bk[a]=1;
    }
    vector<int> dp(n+2, 0);
    dp[n]=1;
    REPD(i, n){
        if(bk[i]==1){
            dp[i]=0;
            continue;
        }
        dp[i]=(dp[i+1]+dp[i+2])%MOD;
    }
    cout << dp[0] << endl;

    return 0;
}
