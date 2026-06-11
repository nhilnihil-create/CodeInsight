#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

vector<vector<int>> Factrization(int X);

int main(){
    int X, X1, X2, loop_n_B, X2_tmp;
    int A = 0, B = 0;
    vector<vector<int>> factors_;

    std::cin >> X;
    
    factors_ = Factrization(X);

    for(int i = 0; i < factors_.size(); i++ ){
    //    std::cout << factors_[i][0] << " " << factors_[i][1] << "\n";
    //因数分解のペアループ
        X1 = factors_[i][0];
        X2 = factors_[i][1];
    //    std::cout << X1 << "\n";
    //    std::cout << X2 << "\n";
        loop_n_B = (int)ceil(pow((float)X2,1.0/4.0))+1;
        //std::cout << pow((float)X,1.0/4.0) << "\n";
        //std::cout << loop_n_B << "\n";
        for(int i = -loop_n_B; i <= loop_n_B; i++){
            //B探索ループ
            X2_tmp = 5*(int)round(pow((float)i,4.0)) + 10*X1*(int)round(pow((float)i,3.0)) + 10*(int)round(pow(X1,2.0))*(int)round(pow((float)i,2.0)) + 5*(int)round(pow((float)X1,3.0))*i + (int)round(pow((float)X1,4.0));
        //    B = i^3;
        //    std::cout << B;
        //    std::cout << i << " " << X2_tmp << "\n";
            if(X2_tmp == X2){
                B = i;
                A = X1 + B; 
                goto print_answer;
            }
        }
    }
    print_answer:
    std::cout << A << " " << B;
}

vector<vector<int>> Factrization(int X){
    vector<vector<int>> factors = {};
    int n_loop, a, b;

    n_loop = (int)floor(sqrt((float)X));
    for(int i =1; i <= n_loop; i++){
        if(X%i == 0){
            a = i;
            b = X/i;
            factors.push_back({a, b});
        }
    }
    return factors;
}