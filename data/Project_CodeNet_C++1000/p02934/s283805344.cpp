#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
    int N;
    double A;
    double ans = 0.0;
    std::cin >> N;

    for(int i = 0; i < N; i++){
        std::cin >> A;
        ans = ans + 1/A;
    }

    std::cout << setprecision(16) << 1/ans;
}
