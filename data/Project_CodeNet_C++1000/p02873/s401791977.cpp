#include<bits/stdc++.h>
// #define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
#define MOD 1000000007
using namespace std;
using ll = long long;
typedef vector<int> vi;

signed main() {
    string s;
    cin >> s;
    ll ans = 0;
    vi a(s.length()+1);
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '<'){
            a[i+1] = max(a[i+1], a[i]+1);
        }
    }
    cout << endl;
    for(int i = s.length()-1; i >= 0; i--){
        if(s[i] == '>'){
            a[i] = max(a[i+1]+1, a[i]);
        }
    }
    rep(i, a.size()){
        ans += a[i];
    }
    cout << ans << endl;
}