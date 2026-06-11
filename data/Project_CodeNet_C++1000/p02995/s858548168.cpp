#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

long long eucledean(long long a, long long b){
    long long r;
    if(a<b) std::swap(a,b);
    if(b<1) return b;
    while((r=a%b)!=0){
        a = b; b = r;
    }
    return b;
}

int main(){
    ll a,b,c,d,e;
    std::cin >> a >> b >> c >> d;
    e = c*d/eucledean(c,d);

    ll ans = 0;
    ans += b - b/c - b/d + b/e;
    ans -= (a-1) - (a-1)/c - (a-1)/d + (a-1)/e;

    std::cout << ans << "\n";
    return 0;
}