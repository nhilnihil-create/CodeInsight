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
int ans[100010];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S; cin >> S;
    int left = 0, right = 0;
    int i = 0;
    while(left < S.length()) {
        int num[2] = {};
        while(S[i] == 'R') {num[(i - left) % 2]++; i++;}
        right = i;
        while(S[i] == 'L') {num[(i - right + 1) % 2]++; i++;}
        left = i;
        ans[right - 1] = num[0];
        ans[right] = num[1];
    }
    rep(i, S.length()) {
        if(i != 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
