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

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    int A[200010], F[200010];
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> F[i];
    sort(A, A + N);
    sort(F, F + N, greater<int>());
    int ok = INF2;
    int ng = -1;
    while(abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        int cnt = 0;
        rep(i, N) {
            int cost = F[i] * A[i];
            if(cost < mid) continue;
            int lack = cost - mid;
            cnt += (lack + F[i] - 1) / F[i];
            if(cnt > K) break;
            
        }
        //cerr << mid << " " << cnt << endl;
        if(cnt <= K) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;

    return 0;
}
