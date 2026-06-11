#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int main(){
    string s, t;
    cin >> s >> t;
    map<char, vector<ll>> mp;
    ll sn = s.size(), tn = t.size();
    rep(i, sn){
        mp[s[i]].push_back(i);
    }
    rep(i, tn){
        if (mp.find(t[i]) == mp.end()){
            cout << -1 << endl;
            return 0;        
        }
    }

    int left = 0;
    ll ans = 0;
    while(left < tn){
        ll a = -1;
        vector<int> pos(26);
        while(left < tn){
            char c = t[left];
            int pi = pos[c-'a'];
            int si = upper_bound(mp[c].begin()+pi, mp[c].end(), a) - mp[c].begin();
            if (si == mp[c].size()) break;
            else{
                a = mp[c][si];
                pos[c-'a'] = si + 1;
                left++;
            }
        }
        if (left == tn){
            ans += a + 1LL;
        }else{
            ans += sn;
        }
    }
    cout << ans << endl;
    return 0;
}