#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF 1e18
#define INF 1e9
using namespace std;

#define fs first
#define sc second

using P = pair<ll,ll>;
using Pll = pair<P,ll>;
using PQ = priority_queue<P,vector<P>,greater<P>>;

signed main(){
    ll n,m;
    cin >> n >> m;
    bool is_solved[n] = {false};
    ll wa_cnt[n] = {};
    rep(i,0,m){
        ll p;
        string s;
        cin >> p >> s;
        if(!is_solved[p-1]){
            if(s == "AC"){
                is_solved[p-1] = true;
            }
            else{
                wa_cnt[p-1]++;
            }
        }
    }

    ll wa_ans = 0,ac_ans = 0;
    rep(i,0,n){
        if(is_solved[i]){
            ac_ans++;
            wa_ans += wa_cnt[i];
        }
    }
    cout << ac_ans << " " << wa_ans << endl;
    return 0;
}
