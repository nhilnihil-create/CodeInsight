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
using PQ = priority_queue<P,vector<P>,greater<P>>;

signed main(){

    string s;
    cin >> s;
    ll n = s.size();
    ll ans[n] = {};

    ll cnt = 0;ll memo_index = 0,border_index = -1;
    rep(i,0,n-1){
        cnt++;
        if(s[i] == 'R' && s[i+1] == 'L'){
            memo_index = i;
        }
        else if(s[i] == 'L' && s[i+1] == 'R'){
            ans[memo_index] = cnt/2;
            ans[memo_index+1] = cnt - cnt/2;
            if((memo_index-border_index) % 2) swap(ans[memo_index],ans[memo_index+1]);
            cnt = 0;
            border_index = i;
        }
    }
    cnt++;
    ans[memo_index] = cnt/2;
    ans[memo_index+1] = cnt - cnt/2;
    if((memo_index-border_index) % 2) swap(ans[memo_index],ans[memo_index+1]);

    rep(i,0,n) cout << ans[i] << (i-n+1?" ":"");
    cout << endl;
    return 0;
}