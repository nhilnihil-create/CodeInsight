#include<iostream>
#include<algorithm>
#include<vector>

#define rep(i,n) for(int i=0; i<(n); ++i)

int main(){
    int n,k; std::cin >> n >> k;
    std::vector<int> h(n);
    rep(i,n) std::cin >> h[i];
    std::sort(h.begin(),h.end(),std::greater<int>());

    long ans=0;
    for(int i=k; i<n; ++i)
        ans += h[i];
    std::cout << ans << std::endl;
    return 0;
}