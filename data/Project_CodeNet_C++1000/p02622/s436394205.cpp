#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
#define INF 999999999
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

using llong = long long;
using namespace std;

int main(){
    string s,t;
    int ans=0;
    cin >> s >> t;
    int len = s.length();
    // cout << len << endl;
    rep(i,len) if(s[i] != t[i]) ans++;
    cout << ans << endl;
}