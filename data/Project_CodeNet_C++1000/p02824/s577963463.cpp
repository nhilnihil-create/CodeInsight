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
    int N, M, V, P;
    cin >> N >> M >> V >> P;
    int A[100010];
    rep(i, N) cin >> A[i];
    sort(A, A + N, greater<int>());
    // rep(i, N) cout << A[i] << " ";
    // cout << endl;
    int ok = A[0] + 1;
    int ng = -1;
    while(abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        int id = 0;
        rep(i, N) if(A[id] > A[i] && A[i] >= mid) id = i;
        int score = A[id] + M;
        int v = V;
        int need = 0;
        int same = 0;
        int margin = M * (V - 1);
        int lose = 0;
        priority_queue<int> que;
        rep(i, N) {
            if(i == id) continue;
            if(score < A[i]) {margin -= M; lose++;}
            if(score == A[i]) {same++; que.push(M);}
            if(score > A[i]) {margin -= min(M, score - A[i]); que.push(M - min(M, score - A[i])); }
        }
        while(lose + 1 < P && que.size()) {margin -= que.top(); que.pop(); lose++;}
        //cout << mid << " " << lose << " " << margin << endl;
        if(lose < P && margin <= 0) ok = mid;
        else ng = mid;
    }
    int ans = 0;
    rep(i, N) if(A[i] >= ok) ans++;
    cout << ans << endl;



    return 0;
}
// N = 6, M = 1, V = 5, P = 2
// 0 1 2 3 4 5
// 3 2 2 1 1 0
// 3 2 2 2 2 0 (remain = 4)