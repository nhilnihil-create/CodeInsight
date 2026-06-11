#include<iostream>
#include<map>
#include<vector>
using namespace std;


int main(){
    long long N, A, grand_sum = 0;
    long long n, ans;
    std::cin >> N;

    vector<long long> A_list(N);
    map<long long, long long> balls;

    for(int i = 0; i < N; i++){
        std::cin >> A;
        A_list[i] = A;
        if(balls.count(A)){
            balls[A] = balls[A] + 1;
        }else{
            balls[A] = 1;
        }
    }

    std::map<long long, long long>::iterator iter = balls.begin();
    for(int i = 0; i < balls.size(); i++){
        n = iter->second;
        grand_sum = grand_sum + n * (n - 1) / 2;
        iter++;
    }

    //std::cout << grand_sum << "\n";

    for(int k = 0; k < N; k ++ ){
        ans = grand_sum - (balls[A_list[k]] - 1);
        std::cout << ans << "\n";
    }
}