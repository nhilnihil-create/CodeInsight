#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

int main(){
    ll n;
    cin >> n;

    vector<int> a(n+1);
    rep(i, n)cin >> a[i+1];

    vector<bool> inBall(n+1);
    vector<ll> ans;
    for(ll i = n; i > 0; --i){
        ll cnt = 0;
        for(ll j = 2*i; j <= n; j+=i){
            if(inBall[j])cnt++;
        }

        if((cnt&1) != a[i]){
            ans.push_back(i);
            inBall[i] = true;
        }
    }

    cout << ans.size() << endl;
    rep(j, ans.size())cout << ans[ans.size()-j-1] << " ";
}