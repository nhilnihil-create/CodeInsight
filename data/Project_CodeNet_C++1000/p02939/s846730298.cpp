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
    cin >> s;
    int n = s.length();
    vector<int> a(n+1,0);
    a[0]=0;
    a[1]=1;
    a[2]=a[1]+(s[0]!=s[1]);
    FOR(i,3,n+1) {
        if(s[i-1]==s[i-2]) a[i]=a[i-3]+2;
        else a[i]=a[i-1]+1;
        //cout << i<<" "<<a[i] << endl;
    }
    cout << a[n] << endl;
    return 0;
}

