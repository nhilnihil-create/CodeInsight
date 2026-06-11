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
    ll h, w;
    cin >> h >> w;
    
    string s[h];
    rep(i, h)cin >> s[i];

    ll high[h][w] = {};
    ll low[h][w] = {};
    ll left[h][w] = {};
    ll right[h][w] = {};

    rep(i, h)rep(j, w){
        if(i != 0){
            if(s[i-1][j] == '.')high[i][j] = high[i-1][j] + 1;
            if(s[h-i][j] == '.')low[h-i-1][j] = low[h-i][j] + 1;
        }
        if(j != 0){
            if(s[i][j-1] == '.')left[i][j] = left[i][j-1] + 1;
            if(s[i][w-j] == '.')right[i][w-j-1] = right[i][w-j] + 1; 
        }

        if(s[i][j] == '#'){
            high[i][j] = 0;
            left[i][j] = 0;
        }
        if(s[h-i-1][j] == '#')low[h-i-1][j] = 0;
        if(s[i][w-j-1] == '#')right[i][w-j-1] = 0;
    }

    ll ans = 0;
    rep(i, h)rep(j, w){
        if(s[i][j] == '#')continue;

        ans = max(ans, high[i][j] + low[i][j] + left[i][j] + right[i][j] + 1);
    }

    cout << ans << endl;
}