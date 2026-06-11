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

signed main() {
    string s;
    int k;
    cin >> s>> k;
    int n = s.length();
    int ans =0;
    if(n==1) {
        cout << k/2 << endl;
        return 0;
    }
    FOR(i,1,s.length()) {
        if(s[i]==s[i-1]) {
                ans++;
        }
    }
    if(ans==n-1) {
        cout << n*k/2 << endl;
    }
    else if(s[0]!=s[n-1]) {
        ans =0;
        FOR(i,1,s.length()) {
            if(s[i]==s[i-1]) {
                ans++;
                s[i]='.';
            }
        }
        //cout << ans << endl;
        cout << ans*k<< endl;
    }else {
        char ss = s[0];
        char ee = s[n-1];
        int sc = 0;
        int ec = 0;
        rep(i,n) {
            if(ee==s[i])sc++;
            else break;
        }
        rrep(i,n) {
            if(ss==s[i])ec++;
            else break;
        }
        ans =0;
        FOR(i,1,s.length()) {
            if(s[i]==s[i-1]) {
                ans++;
                i++;
            }
        }
        cout << ans*k-(sc/2+ec/2-(sc+ec)/2)*(k-1) << endl;
    }
    return 0;
}

