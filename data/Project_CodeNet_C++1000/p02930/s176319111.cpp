#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define siz(v) (ll)(v).size()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, x, n) for (ll i = x; i < (ll)(n); i++)
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
const ll mod = 998244353;
const ll INF = 1000000099;
vector<ll> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
//cin.tie(0);
//ios::sync_with_stdio(false);



signed main(){
    ll n;cin>>n;
    vector<vector<ll>> ans(n+1,vector<ll>(n+1));
    for(int i=0;i < n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int x=i,y=j,cnt=1;
            while(1){
                if((x&1) != (y&1)){
                    ans[i][j]=cnt;
                    break;
                }else{
                    x/=2;
                    y/=2;
                    cnt++;
                }
            }
        }
    }

    for(int i=0;i < n-1;i++)
    {
        for(int j=i+1;j <n;j++)
        {
            cout<<ans[i][j]<<(j==n-1?'\n':' ');
        }
    }    
}
