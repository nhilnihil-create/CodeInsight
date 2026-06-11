//#pragma GCC optimize ('O3')
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mp make_pair
#define f first
#define s second
#define pb push_back

const int N = 2e5 + 5;
const int M = 17 + 5;
const int W = 1000 + 5;
const int OO = 1e9;
const int mod = 1e9 + 7;

string s;
map<pair<int,string>,int> dp,vis;

int solve(int idx, string x) {

    if(idx==s.size()) return 0;

    int &ret = dp[mp(idx,x)];

    if(vis[mp(idx,x)]) return ret;
    
    vis[mp(idx,x)] = 1;

    ret = -OO;

    string c;
    c += s[idx];

    if(x!=c) ret = max(ret,1+solve(idx+1,c));

    if(idx<s.size()-1) {
        c += s[idx+1];
        if(x!=c) ret = max(ret,1+solve(idx+2,c));
    }

    return ret;

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> s;

    cout << solve(0,"") << '\n';

    return 0;
}