#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e13;
const int mod = 1e9+7;
#define ll long long
map<char, int> m;
signed main() {
    int a,b,m;
    cin >> a >> b>> m;
    vector<int> aa(a);
    rep(i,a) cin >> aa[i];
    vector<int> bb(b);
    rep(i,b) cin >> bb[i];
    int mi = inf;
    rep(i,m) {
        int x,y,c;
        cin >> x >> y >> c;
        x--; y--;
        mi = min(aa[x]+bb[y]-c,mi);
    }
    sort(aa.begin(),aa.end());
    sort(bb.begin(),bb.end());
    mi = min(aa[0]+bb[0],mi);
    cout << mi << endl;
  return 0;
}

