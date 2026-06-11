#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;

ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

const int MOD = 1000000007;



int main() {
    ll n,a,b; cin >> n >> a >> b;
    ll ans1 = n/(a+b) * a;
    if(n%(a+b) <= a) {
        ans1 += n%(a+b);
    }else{
        ans1 += a;
    }
    cout << ans1;
}
