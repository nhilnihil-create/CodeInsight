#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<cstring>
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
    int h, w; cin >> h >> w;
    vector<string> v;
    REP(i, h) {
        string tmp; cin >> tmp;
        v.push_back(tmp);
    }
    int dp[110][110];
    memset(dp, 0, sizeof(dp));

    REP(i, h) {
        REP(j, w) {
            if (i == 0 && j == 0) {
                continue;
            }
            if (i == 0) {
                if (v[i][j] == v[i][j-1]) {
                    dp[i][j] = dp[i][j-1];
                } else {
                    dp[i][j] = dp[i][j-1] + 1;
                }
            } else if (j == 0) {
                if (v[i][j] == v[i-1][j]) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j] + 1;
                }
            } else {
                if ((v[i][j] == v[i][j-1]) && (v[i][j] == v[i-1][j])) {
                    dp[i][j] = min(dp[i][j-1], dp[i-1][j]);
                } else if ((v[i][j] == v[i][j-1]) && (v[i][j] != v[i-1][j])) {
                    dp[i][j] = min(dp[i][j-1], dp[i-1][j]+1);
                } else if ((v[i][j] != v[i][j-1]) && (v[i][j] == v[i-1][j])) {
                    dp[i][j] = min(dp[i][j-1]+1, dp[i-1][j]);
                } else {
                    dp[i][j] = min(dp[i][j-1]+1, dp[i-1][j]+1);
                }
            }
        }
    }
    if (v[0][0] == '.' && v[h-1][w-1] == '.') {
        cout << dp[h-1][w-1] / 2 << endl;
    } else {
        cout << dp[h-1][w-1] / 2 + 1 << endl;
    }
    return 0;
}