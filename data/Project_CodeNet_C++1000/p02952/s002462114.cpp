#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 2e9
#define LINF 1e18
#define MOD 1000000007
#define PI 3.141592653589793
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define input(x, n)for(ll i = 0; i <(ll)(n); i++)cin >> x[i];
#define until(i,n) for(ll i = 1; i <= (ll)(n); i++)
#define all(x) (x).begin(),(x).end()
#define dump(x) cout << #x << "=" << (x) << endl
#define YES(n) cout << ((n) ? "YES" : "NO") << endl
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl

int main(){
    ll n;
    cin >> n;
    int ans = 0;
    until(i, n){
        ll a = i;
        int cnt = 0;
        while(a > 0){
            a/=10;
            cnt++;
        }
        if(cnt%2 == 1)ans++;
    }

    cout << ans << endl;
}