//
//AtCoder Beginner Contest 137
//D - Summer Vacation
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

ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }            //最小公倍数

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> tbl(200000);
    REP(i, n) {
        int a, b;
        cin >> a >> b;
        tbl[a-1].push_back(b);
    }

    priority_queue<int, vector<int>, less<int>> pq;
    int ans = 0;
    REP(i, m){
        for(int b : tbl[i]) pq.push(b);
        if (pq.empty()) continue;
        ans += pq.top(); pq.pop();
    }
    cout << ans << endl;
    return 0;
}
