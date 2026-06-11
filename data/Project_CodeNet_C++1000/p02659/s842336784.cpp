#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;
const ll MOD = 1000000007;
const ll MX = 0; //最大値

#define rep(i,n) for(ll i=0; i<(ll)(n); i++)
#define ALL(x) (x).begin(),(x).end()
#define MAX(x) *max_element(ALL(x))
#define PB push_back
#define F first
#define S second

int main(){
    ll A; long double B; cin >> A >> B;
    ll c = B*100 + 0.1;
    ll ans = A * c / 100;
    cout << ans << endl;
    return 0;
}