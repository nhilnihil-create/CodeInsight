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

vector<int> nxt[26];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S, T;
    cin >> S >> T;
    S += S;
    rep(i, 26) {
        rep(j, S.length()) {
            if(S[j] == 'a' + i) nxt[i].push_back(j);
        }
    }
    ll ans = 0;
    int x = -1;
    rep(i, T.length()) {
        int prev = x;
        int k = T[i] - 'a';
        auto itr = lower_bound(nxt[k].begin(), nxt[k].end(), x + 1);
        if(itr == nxt[k].end()) {
            cout << -1 << endl;
            return 0;
        }
        ans += *itr - prev;
        x = *itr % (S.length() / 2);
        //cout << prev << " "<< x <<" " << ans << endl;
    }
    cout << ans << endl;


    return 0;
}

