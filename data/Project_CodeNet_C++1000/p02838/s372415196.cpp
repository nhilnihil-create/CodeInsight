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
#define int long long
int cnt[64] = {};
signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    int A[300010];
    rep(i, N) cin >> A[i];
    int ans = 0;
    rep(i, N) {
        rep(j, 62) {
            if(A[i] & (1LL << j)) cnt[j]++;
        }
    }
    rep(i, N) {
        rep(j, 62) {
            if(!(A[i] & (1LL << j))) continue;
            int k = (1LL << j) % mod;
            cnt[j]--;
            int remain = (N - 1) - cnt[j];
            //cout << j << " " << remain << endl;
            ans = (ans + k * remain) % mod;
            cnt[j]++;
        }
    }
    //rep(j, 61) if(cnt[j] > 0) cout << j << " " << cnt[j] << endl;
    cout << ans << endl;

    return 0;
}
