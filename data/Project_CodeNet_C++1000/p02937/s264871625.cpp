#include <bits/stdc++.h>
#include <vector> 
#include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e9;
const int mod = 1e9+7;

int arr[26];
signed main(){
    string s, t;
    cin>>s >>t;
    vector<vector<int>> arr(26);
    rep(i,s.length()) arr[s[i]-'a'].push_back(i);
    rep(i,s.length()) arr[s[i]-'a'].push_back(i+s.length());

    int ans = 0;
    int p =0;
    rep(i,t.length()) {
        int c = t[i]-'a';
        if(arr[c].size()==0) {
            cout << -1 << endl;
            return 0;
        } 
        p = *lower_bound(arr[c].begin(), arr[c].end(), p)+1;
        if(p>=s.length()) {
            p-=s.length();
            ans += s.length();
        }
    }
    ans += p;
    cout << ans << endl;

    return 0;
}
