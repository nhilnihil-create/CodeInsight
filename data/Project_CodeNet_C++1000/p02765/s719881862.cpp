#include <iostream>
#define rep(i,n) for(int i=0; i<(n); ++i)

int main() {
    int n,r; std::cin >> n >> r;
    int rate=r;
    if(n < 10)
        rate += 100*(10-n);
    std::cout << rate << std::endl;
    return 0;
}