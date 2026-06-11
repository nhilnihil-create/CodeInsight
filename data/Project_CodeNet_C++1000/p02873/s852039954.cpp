#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
using ll = long long;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    ll sum = 0, ans = 0;
    vector<ll>v(n+1, 0);
    rep(i, 0, n){
        if(s[i] =='<'){
            v[i+1] = v[i] +1;
        }
    }
    rrep(i, n, 0){
        if(s[i-1] == '>'){
            v[i-1] = max(v[i-1], v[i]+1);
        }
    }
    rep(i, 0, n+1){
        ans += v[i];
    }
    cout << ans << endl;
}