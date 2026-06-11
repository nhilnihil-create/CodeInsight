#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
const int inf = 1 << 30;
const ll linf = 1e18;
template<class T> void chmin(T& x, T y){if(x > y) x = y;}
template<class T> void chmax(T& x, T y){if(x < y) x = y;}

ll k, q;
ll d[5010];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k >> q;
    for(int i = 1; i <= k; i++){
        cin >> d[i];
    }
    for(int i = 0; i < q; i++){
        ll n, x, m;
        cin >> n >> x >> m;
        n--;
        ll ans = n;
        ll sum = x;
        for(int j = 1; j <= k; j++){
            ll md = d[j] % m;
            sum += md * (n / k);
            if(md == 0) ans -= n / k;
            if(n % k >= j) sum += md;
            if(md == 0 && n % k >= j) ans--;
        }
        cout << ans - (sum / m) + (x / m) << endl;
    }
    return 0;
}