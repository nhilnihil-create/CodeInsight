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

int L[200010];
int R[200010];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, K, C;
    cin >> N >> K >> C;
    string S; cin >> S;
    int cnt = K;
    for(int i = 0; i < S.length(); i++) {
        if (S[i] == 'o') {
            L[i] = cnt;
            i += C;
            cnt--;
        }
    }
    if(cnt < 0) return 0;
    cnt = K;
    for(int i = S.length() - 1; i >= 0; i--) {
        if (S[i] == 'o') {
            R[i] = cnt;
            i -= C;
            cnt--;
        }
    }
    if(cnt < 0) return 0;
    // rep(i, S.length()) cout << L[i] << " ";
    // cout << endl;
    // rep(i, S.length()) cout << R[i] << " ";
    // cout << endl;
    rep(i, S.length()) {
        if(L[i] && R[i]) cout << i + 1 << endl;
    }


    return 0;
}
