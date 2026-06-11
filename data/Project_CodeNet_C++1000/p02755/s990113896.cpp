#include<iostream>
#include<cmath>

int main(){

    double A,B;
    int A_min, A_max, B_min, B_max;
    int ans = -1;

    std::cin >> A >> B;

    A_min = (int)round(ceil(A/0.08)); 
    A_max = (int)round(ceil((A+1.0)/0.08))-1;
    B_min = (int)round(ceil(B/0.10)); 
    B_max = (int)round(ceil((B+1.0)/0.10))-1;

    if(A_min <= B_min){
        if(A_max >= B_min){
            ans = B_min;
        }
    }else if(A_min >= B_min){
        if(B_max >= A_min){
            ans = A_min;
        }
    }

    std::cout << ans;

}