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

int cnt[10][10];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    int ans = 0;
    REP(A, 1, N) {
        string S = to_string(A);
        int l = S.front() - '0';
        int r = S.back() - '0';
        //cout << l << " " << r << endl;
        cnt[l][r]++;
    }
    REP(B, 1, N) {
        string S = to_string(B);
        int l = S.front() - '0';
        int r = S.back() - '0';
        ans += cnt[r][l];
    }
    cout << ans << endl;


    return 0;
}
// 1 