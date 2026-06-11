#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

void dfs ( char pre_char, int n, string s, vector<string> &ans ) {
    if ( (int)s.length() == n ) {
        ans.push_back(s);
        return;
    }
    for ( int i = 'a'; i <= pre_char + 1; ++i ) {
        dfs(((i>pre_char)?(char)(pre_char+1):pre_char), n, s+(char)i, ans);
    }
    return;
}

int main(){
    int n;
    cin >> n;
    vector<string> ans;
    dfs('a', n, "a", ans);
    for ( auto a : ans ) {
        cout << a << endl;
    }  
    return 0;
}
