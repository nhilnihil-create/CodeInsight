#include<cmath>
#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    double A, B;
    long long ans, A_l, B_l;

    std::cin >> A >> B;
    A_l = (long long)A;
    B_l = (long long)round(B * 100.0);
    // std::cout << A_l << " " << B_l << "\n";
    // std::cout << A_l * B_l << "\n";
    ans = (A_l*B_l - (A_l*B_l)%100)/100;
    //ans = (long long)round(floor(A * B));
    std::cout << dec << ans;

}