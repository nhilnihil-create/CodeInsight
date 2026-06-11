#include <iostream>
#include <vector>

int main(void){
    int n, ans=1000001;
    std::cin >> n;
    std::vector<int> x(n);
    for(int i=0; i<n; ++i) std::cin >> x.at(i);

    for(int i=1; i<101; ++i){
        int tmp = 0;
        for(int j=0; j<n; ++j){
            tmp += (x.at(j) - i) * (x.at(j) - i);
        }
        if(tmp < ans) ans = tmp;
    }

    std::cout << ans << std::endl; 

    return 0;
}