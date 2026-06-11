//
//AtCoder Beginner Contest 158
//D
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
#include <bitset>

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
using Graph = vector<vector<int>>;

const double PI = 3.14159265358979323846;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }            //最小公倍数

int main()
{
    string s;
    cin >> s;

    int q;
    cin >> q;

    int rf=0;   //0:normal, 1:reverce
    vector<string> sadd(2);
    REP(i, q){
        int t;
        cin >> t;
        if (t==1) {
            if (rf==0) rf=1; 
            else rf=0;
        }
        if (t==2){
            int f;
            string c;
            cin >> f >> c;
            if ((f==1) && (rf==0)) sadd[0] = c + sadd[0];
            if ((f==1) && (rf==1)) sadd[1] = sadd[1] + c;
            if ((f==2) && (rf==0)) sadd[1] = sadd[1] + c;
            if ((f==2) && (rf==1)) sadd[0] = c + sadd[0];
        }
    }
    string ans = sadd[0] + s + sadd[1];
    if (rf==1) reverse(ans.begin(), ans.end());

    cout << ans << endl;
    return 0;
}
