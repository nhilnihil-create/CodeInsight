#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n); i >= 0; i--)
#define loop(i, r, n) for (int i = (r); i < (n); i++)
#define FOR(n) for (int _i = 0; _i < (n); _i++)
 
#define pb push_back
#define all(in) in.begin(),in.end()
 
using ll = long long;
using ull = unsigned long long;
using namespace std;
 
int main(){
    string s; cin >> s;
    ll n = s.length();
    ll ans = 0, save = 0;
    rep(i,n){
        int d = s[n-1-i] - '0';
        if(d + save <= 4){ ans += d + save; save = 0; }
      	else if(d + save == 5 && i < n-1 && s[n-2-i]-'0' <= 4){ ans += d + save; save = 0; }
      	else if(d + save == 5 && i == n-1){ ans += d + save; save = 0; }
        else { ans += 10 - d - save; save = 1; }
    }
    if(save) ans++;
    cout << ans << endl;
}