#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <iomanip>
#include <bitset>
#include <set>
#include <map>

#define rep(i,n) for (int i = 0; i < (n); i++)
#define FOR(i,a,b) for (int i=(a); i < (b); i++)
#define INF 100000000000
#define MOD 1000000007 //10^9+7
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 負の数にも対応した % 演算
long long mod(long long val, long long m) {
    long long res = val % m;
    if (res < 0) res += m;
    return res;
}


int main()
{
    int a, b, m;
    cin >> a >>b >> m;
    vector<int> arra(a), arrb(b);
    rep(i,a) cin >> arra[i];
    rep(i,b) cin >> arrb[i];

    int discount[m][3];
    rep(i,m) {
        rep(j,3) {
            cin >> discount[i][j];
        }
    }
    
    vector<int> tmpv;
    tmpv = arra;
    int ans = 0;
    sort(tmpv.begin(), tmpv.end());
    ans += tmpv[0];
    tmpv = arrb;
    sort(tmpv.begin(), tmpv.end());
    ans += tmpv[0];

    rep(i,m) {
        int tmp = arra[discount[i][0]-1] + arrb[discount[i][1]-1] - discount[i][2];
        ans = min(tmp, ans) ;
    }

    cout << ans << endl;
    return 0;
}
