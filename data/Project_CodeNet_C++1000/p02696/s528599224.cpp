#include<iostream>
#include<cmath>
using namespace std;

int main(){
    double N, A, B, ans_d, ans_tmp, x;
    long long ans_l;

    std::cin >> A >> B >> N;
//    std::cout << A << B << N << "\n";
    ans_d = 0.0;
    //for(long long i = 1; i <= (long long)N; i++){
    if(N >= B){
        x = B - 1.0;
    }else{
        x = N;
    }
    ans_tmp = floor(A*round(x)/B);
    //std::cout << ans_tmp;
    ans_tmp = ans_tmp - A * floor(round(x)/B);

    if(ans_tmp > ans_d){
        ans_d = ans_tmp;
    }
    //}

    ans_l = (long long)round(ans_d);

    std::cout << ans_l;

}