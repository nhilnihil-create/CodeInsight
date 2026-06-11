#include<iostream>
#define rep(i,n) for(int i=0; i<(n); ++i)

int main(){
    int n,m; std::cin >> n >> m;
    int a, total=0;
    rep(i,m){
        std::cin >> a;
        total += a;
    }
    std::cout << (total > n ? -1 : n-total) << std::endl;
    return 0;
}