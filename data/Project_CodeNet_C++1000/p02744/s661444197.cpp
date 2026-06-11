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

vector<string> T;
int N;
void dfs(string S = "", int depth = 0, int c = 1) {
    if (depth >= N) {
        T.push_back(S);
        return;
    }
    rep(i, c) {
        S.push_back('a' + i);
        dfs(S, depth + 1, max(c, i + 2));
        S.pop_back();
    }
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    dfs();
    for(auto& e: T) {
        cout << e << endl;
    }

    return 0;
}
