#include<iostream>
#include<vector>
#define rep(i,n) for(int i=0; i<(n); ++i)

int main(){
    int n; std::cin >> n;
    std::vector<int> p(n);
    rep(i,n) std::cin >> p[i];
    int ans=1, m=p[0];
    for(int i=1; i<n; ++i){
        if(m >= p[i]){
            m = p[i];
            ++ans;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}