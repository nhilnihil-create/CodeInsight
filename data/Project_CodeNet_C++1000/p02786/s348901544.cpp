#include<cmath>
#include<iostream>

#define rep(i,n) for(int i=0; i<(n); ++i)
#define ll long long

int main(){
    ll h; std::cin >> h;
    ll ans=0, depth=std::log2(h);
    rep(i,depth+1) ans += std::pow(2,i);
    std::cout << ans << std::endl;
    return 0;
}