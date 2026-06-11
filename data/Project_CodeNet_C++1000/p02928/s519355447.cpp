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
#define MOD 1000000007
#define MAXR 100000
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define INITA(a,i,j,v) for(ll k=i;k<=j;k++){a[k]=v;}

int main() {
    int n; cin >> n;
    ll k; cin >> k;
    ll a[2001]; INITA(a, 0, 2000, 0);
    REP(i, n) {
        cin >> a[i];
    }
    //   x       y      z
    // 3 2 1 | 3 2 1 | ...
    // 元の整数列だとO(n^2)で確認可能
    // b[i]: i+1番目の数以降の転倒数
    // c[i]: 0番目の数以降の転倒数
    // 各セクションで値ごとにb, それより後のセクションに関してc
    int b[2001]; INITA(b, 0, 2000, 0);
    int c[2001]; INITA(c, 0, 2000, 0);
    FOR(i, 0, n-1) {
        int tmpb = 0;
        int tmpc = 0;
        FOR(j, 0, n-1) {
            if ((i != j) && (a[i] > a[j])) {
                if (i < j) {
                    tmpb++;
                }
                tmpc++;
            }
        }
        b[i] = tmpb;
        c[i] = tmpc;
    }

    ll res = 0;

    // a[i]ごとに回す
    REP(i, n) {
        // セクション内
        res += (b[i] * k) % MOD;
        res %= MOD;

        // セクション外
        // 3セクションだとすると、123,23。21... k(k-1)/2
        res += c[i] * ((k * (k-1) / 2) % MOD) % MOD;
        res %= MOD;
    }
    cout << res << endl;
    // REP(i, n) {
    //     cout << b[i] << endl;
    // }
    // cout << endl;
    // REP(i, n) {
    //     cout << c[i] << endl;
    // }
    return 0;
}