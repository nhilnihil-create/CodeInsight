#include <bits/stdc++.h>

#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9+7;
const ll LINF = 1LL << 60;
const int INF = 1e9 + 7;

map<ll, ll> prime;

int main(){
    ll n, m, v, p;
    cin >> n >> m >> v >> p;

    vector<ll> a(n);
    rep(i, n)cin >> a[i];

    sort(ALL(a), greater<ll>());

    ll low = p;
    ll high = n;

    while(low < high){
        ll mid = (low + high + 1) / 2;

        ll point = 0;

        rep(i, n){
            if(i < p-1 || i > mid-1)point += m;
            else {
                if(a[i] > a[mid-1] + m){
                    point = -1;
                    break;
                }
                point += (a[mid-1] + m) - a[i];
            }
        }

        if(point >= m*v)low = mid;
        else high = mid-1;
    } 

    cout << low << endl;
}