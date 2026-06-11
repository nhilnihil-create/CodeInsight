#include<iostream>
#include<cmath>
int main(){
    unsigned long long A,B;
    double bufB;
    std::cin>>A>>bufB;
    B=(unsigned long long)(floor(bufB*100+0.5));
    std::cout<<(unsigned long long)((A*B)/(long double)100.0);
}