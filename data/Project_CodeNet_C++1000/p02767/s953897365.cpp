#include <iostream>
#include <vector>
#define rep(i,n) for(int i=0; i<(n); ++i)

int main() {
    int n; std::cin >> n;
    std::vector<int> x(n);
    rep(i,n) std::cin >> x[i];
    int total=0;
    rep(i,n) total += x[i];
    int ret, ret1=0, ret2=0;
    int mean1=total/n;
    int mean2=mean1+1;
    int tmp=0;
    rep(i,n){
        ret1 += (mean1-x[i]) * (mean1-x[i]);
        ret2 += (mean2-x[i]) * (mean2-x[i]);
    }
    ret = std::min(ret1, ret2);
    std::cout << ret << std::endl;
    return 0;
}