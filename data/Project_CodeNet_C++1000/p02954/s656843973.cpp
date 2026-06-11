//
//AtCoder Beginner Contest 136
//C - Build Stairs
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
    string s;
    cin >> s;

    int len = s.size();
    vector<int> ans(len, 0);

    char flag = 'R';
    int rCnt = 0;
    int lCnt = 0;
    int idx = -1;
    s+="R";
    REP(i, len){
        if (s[i]=='R') {rCnt++;lCnt=0;}
        if (s[i]=='L') {rCnt=0;lCnt++;}
        if (s[i]=='R' && s[i+1]=='L'){
            ans[i] += (rCnt/2 + rCnt%2);
            ans[i+1] += rCnt/2;
            idx = i;
        }
        if (s[i]=='L' && s[i+1]=='R'){
            ans[idx] += lCnt/2;
            ans[idx+1] += (lCnt/2+lCnt%2);
        }
    }
    for(int v: ans) cout << v << " ";
    cout << endl;
    return 0;
}
