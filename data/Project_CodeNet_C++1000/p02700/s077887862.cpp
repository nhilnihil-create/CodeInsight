#include<iostream>
#include<cmath>
using namespace std;
double A, B, C, D;
int main(){
    std::cin >> A >> B >> C >> D;
    double n_ao = ceil(A/D);
    double n_ta = ceil(C/B);
    if(n_ao == n_ta){
        if((int)A%(int)D == 0){
            if((int)C%(int)B == 0){
                std::cout << "Yes";
            }else{
                std::cout << "No";
            }
        }else{
            std::cout << "Yes";
        }
    }else{
        if(n_ao > n_ta){
            std::cout << "Yes";
        }else{
            std::cout << "No";
        }
    }
}