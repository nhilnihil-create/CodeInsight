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

int cnt[100010];
signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int A[100010];
    rep(i, n) cin >> A[i];
    int ans = 1;
    rep(i, n) {
        if(A[i] == 0)
            ans *= 3 - cnt[A[i]];
        else 
            ans *= cnt[A[i] - 1] - cnt[A[i]];
        ans %= mod;
        cnt[A[i]]++;
        //cout << ans << endl;
    }
    cout << ans << endl;

    return 0;
}
// 0 1 0
// a a b
//