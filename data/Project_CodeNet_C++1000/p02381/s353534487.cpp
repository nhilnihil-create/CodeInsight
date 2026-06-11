#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    while(true){
        int n;
        std::cin >> n;
        if(n==0) break;
        double s = 0;
        double sum = 0;
        for(int i=0; i<n; ++i){
            double si;
            std::cin >> si;
            s += si*si;
            sum += si;
        }
        s /= n;
        sum /= n;
        s -= sum*sum;
    std::cout << std::fixed << std::setprecision(6) << std::sqrt(s) << "\n";
    }
    return 0;
}