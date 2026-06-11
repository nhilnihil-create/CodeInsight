#include<iostream>

#define rep(i,n) for(int i=0; i<(n); ++i)

int main(){
    int h,n; std::cin >> h >> n;
    int all=0;
    rep(i,n){
        int a; std::cin >> a;
        all += a;
    }
    std::cout << (all < h ? "No" : "Yes") << std::endl;

    return 0;
}