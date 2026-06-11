#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define mat vector<vector<int>>
const int inf = 1 << 30;
const ll linf = 1e18;
const db EPS = 1e-7;
template<class T> void chmin(T& x, T y){if(x > y) x = y;}
template<class T> void chmax(T& x, T y){if(x < y) x = y;}

int N, D, A;
ll imos[200010];
vector<pll> ms;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> D >> A;
    for(int i = 0; i < N; ++i){
        ll X, H;
        cin >> X >> H;
        ms.emplace_back(pll{X, H});
    }
    sort(ms.begin(), ms.end());
    ll ans = 0;
    for(int i = 0; i < N; ++i){
        ll rest = ms[i].second - imos[i] * A;
        if(rest > 0){    
            ll add = (rest - 1) / A + 1;
            ans += add;
            int it = upper_bound(ms.begin(), ms.end(), pll{ms[i].first + 2 * D, inf}) - ms.begin();
            imos[it] -= add;
            imos[i] += add;
        }
        imos[i + 1] += imos[i];
    }
    cout << ans << endl;
    return 0;
}