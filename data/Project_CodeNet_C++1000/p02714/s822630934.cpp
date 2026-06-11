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


int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    string S; cin >> S;
    ll ans = 0;
    ll R = 0, G = 0, B = 0;
    rep(i, N) {
        if(S[i] == 'R') R++;
        if(S[i] == 'G') G++;
        if(S[i] == 'B') B++;
    }
    rep(i, N) {
        rep(k, N) {
            
            int j2 = (k + i);
            if(j2 % 2 == 1) continue;
            int j = j2 / 2;
            if(i == j || i == k || j == k || i > j || j > k) continue;
            if(0 <= j && j < N && S[i] != S[j] && S[j] != S[k] && S[k] != S[i]) ans++;
        }
    }
    cout << R * G * B - ans << endl;

    return 0;
}
// j - i = k - j
// 2j = k + i
