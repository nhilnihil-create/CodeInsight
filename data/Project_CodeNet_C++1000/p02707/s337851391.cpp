#include<iostream>
#include<vector>
#define rep(i,n) for(int i=0; i<(n); ++i)

int main(){
    int n; std::cin >> n;
    std::vector<int> a(n,0);
    rep(i,n-1){
        int k; std::cin >> k;
        if(k > 0) ++a[k-1];
    }
    rep(i,n) std::cout << a[i] << std::endl;
    return 0;
}