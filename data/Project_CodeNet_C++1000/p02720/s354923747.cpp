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

vector<int> v;
set<int> st;
void dfs(string S, int depth = 0) {
    if(depth > 9) return;
    if(st.find(stoll(S)) == st.end()) {
        v.push_back(stoll(S)); 
        st.insert(stoll(S));
    } else {
        return;
    }
    char c = S.back();
    char c1 = c - 1;
    char c2 = c + 1;

    string S1 = S + c1;
    string S2 = S + c2;
    S = S + c;

    dfs(S, depth + 1);
    if(c1 >= '0')dfs(S1, depth + 1);
    if(c2 <= '9') dfs(S2, depth + 1);
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int K; cin >> K;
    rep(i, 9) {
        string S = "";
        S +=  (char)('1' + i);
        dfs(S);
    }
    sort(v.begin(), v.end());
    cout << v[K - 1] << endl;
    

    return 0;
}
