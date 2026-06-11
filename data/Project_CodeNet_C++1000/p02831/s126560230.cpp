#include<cmath>
#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

vector<long long> Factrization(long long X);
    //////////////////////////////////////////
    //    因数分解する関数
    //    in   : 整数
    //    out  : 2次元のvector 
    //    ver  : 1.0
    //    概要 : 正の整数での使用のみを想定
    //    include: <vector>, <cmath>
    //////////////////////////////////////////

int main(){
    long long A, B, t_a, t_b;
    long long koyaku = 1;
    std::cin >> A >> B;

    vector<long long> fact_A, fact_B;
    fact_A = Factrization(A);
    fact_B = Factrization(B);

    for(long long i = 0; i < fact_A.size(); i ++){
        t_a = fact_A[i];
        // std::cout << t_a << " ";
        for(long long j = 0; j < fact_B.size(); j++){
            if(fact_B[j] == t_a){
                if(fact_B[j] > koyaku){
                    koyaku = fact_B[j];
                }
            }
        }
    }
    // std::cout << "\n";

    std::cout << A * B / koyaku;

}

vector<long long> Factrization(long long X){
    vector<long long> factors = {};
    int n_loop, a, b;

    n_loop = (long long)floor(sqrt((float)X));
    for(long long i =1; i <= n_loop; i++){
        if(X%i == 0){
            a = i;
            b = X/i;
            factors.push_back(a);
            factors.push_back(b);
        }
    }
    return factors;
}