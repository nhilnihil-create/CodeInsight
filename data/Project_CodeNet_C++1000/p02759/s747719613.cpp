#include<iostream>
#include<cmath>
using namespace std;

double N;
int ans;


int main(){
    std::cin >> N;
    ans = ceil(N/2);
    std::cout << (int)ans;
}
