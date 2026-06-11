#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const int INF = 1e9 + 10;
 
int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    int res = INF;
    rep(i,n-m+1) {
        int count = 0;
        rep(j,m) if(s[j+i] != t[j]) count++;
        chmin(res,count);
    }
    cout << res << endl;
    return 0;
}