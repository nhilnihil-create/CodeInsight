#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
typedef pair<int, int> P;

const ll mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 1152921504606846976

int cnt[26];

int main()
{
    string s,t;
    cin >> s >> t;
    rep(i,s.size()) cnt[s[i]-'a']++;
    bool ok = true;
    rep(i,t.size()){
        if(cnt[t[i]-'a'] == 0) ok = false;
    }
    if(ok){
        vector<ll> pos[26];
        ll n = s.size();
        rep(i,n){
            pos[s[i]-'a'].push_back(i);
        }
        ll ans = 1, tmp = 0;
        rep(i,t.size()){
            int chr = t[i]-'a';
            if(i == 0){
                ans += pos[chr][0];
                tmp = pos[chr][0];
            }else{
                auto iter = upper_bound(pos[chr].begin(), pos[chr].end(), tmp);
                if(iter == pos[chr].end()) {
                    ans += (n + pos[chr][0] - tmp);
                    tmp = pos[chr][0];
                }else{
                    ans += (*iter - tmp);
                    tmp = *iter;
                }
            }
        }
        cout << ans << endl;
    }else{
        cout << -1 << endl;
    }
}