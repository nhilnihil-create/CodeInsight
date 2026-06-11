#include<cmath>
#include<vector>
#include<iostream>
using namespace std;

vector<vector<long long>> Factrization(long long X);
    //////////////////////////////////////////
    //    因数分解する関数
    //    in   : 整数
    //    out  : 2次元のvector 
    //    ver  : 1.0
    //    概要 : 正の整数での使用のみを想定
    //    include: <vector>, <cmath>
    //////////////////////////////////////////


int main(){
    vector<pair<long long, long long>> fact;
    long long X, n;

    std::cin >> X;

    while(1){
        n = Factrization(X).size();
        if(n == 1){
            break;
        }else{
            X++;
        }
        
    }
    
    std::cout << X;


}

vector<vector<long long>> Factrization(long long X){
    vector<vector<long long>> factors = {};
    long long n_loop, a, b;

    n_loop = (long long)floor(sqrt((float)X));
    for(long long i =1; i <= n_loop; i++){
        if(X%i == 0){
            a = i;
            b = X/i;
            factors.push_back({a, b});
        }
    }
    return factors;
}