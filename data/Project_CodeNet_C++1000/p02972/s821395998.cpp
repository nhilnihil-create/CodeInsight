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

//約数列挙
vector<ll> enum_divisors(ll N) {
    vector<ll> res;
    for (ll i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            if (N/i != i) res.push_back(N/i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main(){
    ll n;
    cin >> n;

    vector<int> a(n+1);
    rep(i, n)cin >> a[i+1];

    vector<bool> inBall(n+1);
    vector<ll> ans;
    for(ll i = n; i > 0; --i){
        if(inBall[i] == a[i])continue;

        ans.push_back(i);
    
       vector<ll> divs = enum_divisors(i);
       rep(j, divs.size()){
           inBall[divs[j]] = !inBall[divs[j]];
       }
    }

    cout << ans.size() << endl;
    rep(j, ans.size())cout << ans[ans.size()-j-1] << " ";
}