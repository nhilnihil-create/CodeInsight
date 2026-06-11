//
//三井住友信託銀行プログラミングコンテスト2019
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
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans=0;
    REP(i,10){
        int ip=-1;
        REP(fi,n){
            if (i==(s[fi]-48)) {
                ip = fi;
                break;
            }
        }
        if (ip==-1) continue;
        
        REP(j,10){
            int jp=-1;
            FOR(fj, ip+1, n-1){
                if (j==(s[fj]-48)) {
                    jp = fj;
                    break;
                }
            }
            if (jp==-1) continue;

            REP(k,10){
                FOR(fk, jp+1, n-1){
                    if (k==(s[fk]-48)) {
                        //cout << i << " " << j << " " << k << endl;
                        ans++;
                        break;
                    }
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
