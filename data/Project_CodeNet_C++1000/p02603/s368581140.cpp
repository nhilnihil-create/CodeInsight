#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#define rad2deg(a) ((a)/M_PI * 180.0)
#define deg2rad(a) ((a)/180.0 * M_PI)
const std::string yes = "Yes";
const std::string no  = "No";

int main(){
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    rep(i,n) std::cin >> a[i];

    ll kane = 1000, kabu = 0;
    for(int i=0; i<n-1; i++){
        ll kabu = 0;
        if(a[i]<a[i+1]) kabu = kane/a[i];
        kane += (a[i+1]-a[i])*kabu;
    }

    std::cout << kane << "\n";
    return 0;
}
