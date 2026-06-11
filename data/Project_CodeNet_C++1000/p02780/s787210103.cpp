#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000

int sum[200010];
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    int p[200010];
    rep(i, N) cin >> p[i];
    rep(i, N) sum[i + 1] = sum[i] + p[i];
    double ans = 0.0;
    rep(i, N - K + 1) {
        double score = sum[K + i] - sum[i] + K;
        //cout << score << endl;
        ans = max(ans, score / 2.0);
    }
    cout << fixed << setprecision(12) << ans << endl;

    return 0;
}
