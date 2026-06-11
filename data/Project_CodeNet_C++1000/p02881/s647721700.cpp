#include<iostream>
#include<vector>
#include<cmath>
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
    long long N, ans;
    std::cin >> N;

    vector<vector<long long>> facts;
    facts = Factrization(N);
    ans = N - 1;

    for(long long i = 0; i < facts.size(); i++){
        if(facts[i][0] + facts[i][1] -2 < ans){
            ans = facts[i][0] + facts[i][1] -2;
        }
    }

    std::cout << ans;


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