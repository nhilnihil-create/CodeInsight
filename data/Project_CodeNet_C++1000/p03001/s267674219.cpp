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
    double w, h, x, y;
    cin >> w >> h >> x >> y;

    printf("%.10f", h*w / 2.0);
    if(x == w/2.0 && y == h/2.0)cout << " 1" << endl;
    else cout << " 0" << endl;
}