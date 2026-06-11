#include<iostream>
#define rep(i,n) for(int i=0; i<(n); ++i)

int main(){
    int a,b; std::cin >> a >> b;
    if(a > b) std::swap(a,b);
    rep(i,b) std::cout << a;
    std::cout << '\n';
    return 0;
}