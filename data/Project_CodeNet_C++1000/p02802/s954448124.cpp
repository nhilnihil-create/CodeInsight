#include<bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;


signed main() {
    int n, m;
    cin >> n >> m;
    vi p(m), wa_sum(n);
    vector<string> s(m);
    rep(i, m) cin >> p[i] >> s[i];
    vector<bool> is_AC(n, false);
    vi tmp_wa(n);
    
    ll ans = 0;
    ll ac = 0;

    rep(i, m){
        if(s[i] == "AC"){
            if(is_AC[p[i]-1] == false){
                ac++;
                is_AC[p[i]-1] = true;
            }
        }
        if(s[i] == "WA"){
            if(is_AC[p[i]-1] == false){
                tmp_wa[p[i]-1]++;
            }
        }
    }

    rep(i, n){
        if(is_AC[i]) ans += tmp_wa[i];  
    }
    cout << ac << " " << ans << endl;
}