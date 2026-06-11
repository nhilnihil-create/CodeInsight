#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>

int main(void){
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for(int i = 0; i < n; i++){
        std::cin >> v[i];
    }
    std::sort(v.begin(), v.end());
    double ans = v[0];
    for(int i = 1; i < n; i++){
        ans = (ans + v[i]) / 2;
    }
    std::cout << std::fixed << std::setprecision(15) << ans << std::endl;
    return 0;
}