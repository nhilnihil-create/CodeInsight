#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
const std::string yes = "Yes";
const std::string no  = "No";

int main(){
    int n;
    std::cin >> n;

    ll s = 0;
    std::vector<ll> a(n);
    rep(i,n){
        std::cin >> a[i];
        s += a[i];
    }

    ll ans = s, cnt = 0;
    rep(i,n){
        cnt += a[i];
        ans = std::min<ll>(ans, llabs(cnt - (s - cnt)));
    }

    std::cout << ans << "\n";
    return 0;
}
