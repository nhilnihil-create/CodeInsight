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
    string s;
    cin >> s;
    s = ">"+s+"<";
    vector<int> a(s.length()-1,-1);
    FOR(i,1,s.length()) {
        if(s[i-1]=='>'&&s[i]=='<') {
            a[i-1]=0;
        }
    }
    FOR(i,1,a.size()) {
        if(a[i-1]==0&&s[i]=='<'||s[i]=='<') {
            a[i]=max(a[i-1]+1,a[i]);
        }
        //cout << s[i]<<a[i] << flush;
    }

       // cout << "" << endl;
    RFOR(i,a.size()-2,0) {
        if(a[i+1]==0&&s[i+1]=='>'||s[i+1]=='>') {
            a[i]=max(a[i],a[i+1]+1);

        }
                   // cout << a[i] << s[i+2]<< flush;
 
    }
       // cout << "" << endl;
    int ans = 0;
    rep(i,a.size()) {
        ans += a[i];
       // cout << a[i] << flush;
    }
    //cout << "" << endl;
    cout << ans << endl; 
  return 0;
}

