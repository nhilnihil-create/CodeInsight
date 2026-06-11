#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    long long N, K;
    long long H_tmp;
    long long sum = 0;
    long long sum_tgt = 0;

    std::cin >> N >> K;
    vector<long long> mons_list(N);
    if(K >= N){
        goto finish;
    }
    

    for(long long i = 0; i < N; i++){
        std::cin >> H_tmp;
        sum = sum + H_tmp;
        mons_list[i] = H_tmp;
    }

    std::sort(mons_list.begin(), mons_list.end(), std::greater<long long>());
    for(long long i = 0; i < K; i++){
        sum_tgt = sum_tgt + mons_list[i];
    }
    sum = sum - sum_tgt;
    
    finish:
    std::cout << sum;
}