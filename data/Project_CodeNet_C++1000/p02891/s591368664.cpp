//
//AtCoder Grand Contest 039
//A
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
    ll k;
    cin >> s >> k;

    ll len = SIZEL(s);

    if (count(s.cbegin(), s.cend(), s[0]) == len){
        cout << len*k/2 << endl;
        return 0;
    }

    ll fCnt=0;
    ll lCnt=0;
    REP(i,len){
        if (s[0]==s[i]) fCnt++;
        else break;
    }
    REPD(i,len){
        if (s[len-1]==s[i]) lCnt++;
        else break;
    }

    ll dpCnt=0;
    int c=1;
    char now=s[0];
    FOR(i,1, len){
        if (now==s[i]){
            c++;
        }else{
            dpCnt+=c/2;
            now=s[i];
            c=1;
        }
    }
    if (fCnt%2==1 && lCnt%2==1 && k%2==0) {
        cout << ((dpCnt+1)*k)-1 << endl;
    }else{
        cout << dpCnt*k << endl;
    }
    return 0;
}
