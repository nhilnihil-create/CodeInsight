#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

int main(){
    int n;
    std::cout << std::setprecision(20);

    while(std::cin >> n && n){
        double sum = 0;
        std::vector<double> x;
        for(int i=0; i < n; i++){
            int temp;
            std::cin >> temp;
            x.push_back(temp);
            sum += temp;
        }
        double mean = sum/n;
        double sd = 0;
        for(int i=0; i < n; i++){
            sd += (x[i] - mean) * (x[i] - mean);
        }
        sd /= n;
        sd = std::sqrt(sd);
        std::cout << sd << std::endl;
    }
    
    
}