#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector<double> d(n);
    for(auto& i : d){
        int x;
        std::cin >> x;
        i = x;
    }
    for(auto& i : d){
        int y;
        std::cin >> y;
        i -= y;
        i = std::fabs(i);
    }
    double m1 = 0 , m2 = 0 , m3 = 0 , mInf = 0;
    for(auto& i : d){
        m1 += i;
    }
    for(auto& i : d){
        m2 += i*i;
    }
    m2 = std::sqrt(m2);
    for(auto& i : d){
        m3 += i*i*i;
    }
    m3 = std::pow(m3, 1.0/3.0);
    mInf = *std::max_element(d.begin(), d.end());
    std::cout << std::fixed << std::setprecision(6) << m1 << "\n";
    std::cout << std::fixed << std::setprecision(6) << m2 << "\n";
    std::cout << std::fixed << std::setprecision(6) << m3 << "\n";
    std::cout << std::fixed << std::setprecision(6) << mInf << "\n";
    return 0;
}