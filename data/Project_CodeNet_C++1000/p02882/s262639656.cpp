#include <bits/stdc++.h>

int main(){
    int a, b, x;
    std::cin >> a >> b >> x;
    
    double half = (double)a * (double)a * (double)b / 2.0;
    
    double ans;
    if(half <= (double)x){
        double x_half = (double)x - half;
        double h = x_half / (double)a / (double)a * 2;
        double ans = atan( ((double)b - h) / (double)a) * 180 / M_PI;
        std::cout << std::fixed << std::setprecision(12) << ans << std::endl;
    }else{
        double h = (double)x / (double)a / (double)b * 2;
        double ans = 90 - atan(h / (double)b) * 180 / M_PI;
        std::cout << std::fixed << std::setprecision(12) << ans << std::endl;
    }
    
    return 0;
}

