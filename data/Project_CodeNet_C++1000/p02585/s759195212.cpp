#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL << 60; //intじゃ扱えないことに注意！
#define mod 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++) //範囲外参照とループの初期化に注意！

int main() {
    ll n,k;
    cin >> n >> k;
    vector<ll> p(n),c(n);
    rep(i, n) cin >> p[i];
    rep(i, n) cin >> c[i];
    rep(i, n) p[i]--;
    ll ans = -1e18;
    rep(si, n){    //初期値をn通り回す。
        int x = si;
        vector<int> s;
        ll tot = 0;
        while(1){
            x = p[x];
            s.push_back(c[x]);
            tot += c[x];  //1周期の収支
            if(x == si) break;
        }
        int l = s.size();
        ll t = 0;
        rep(i, l){      //周期のどこで切るか全探索
            t += s[i];  //現在のスコア
            if(i+1 > k) break;
            ll now = t;
            if(tot > 0){
                ll e = (k-(i+1))/l;  //あと何周期か
                now += tot*e;
            } 
            ans = max(ans, now);
        }
    }
    cout << ans << endl;
}