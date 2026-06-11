#include <bits/stdc++.h>

std::vector< int > A;

long long cut_num_calc(int length) {
    long long num = 0;
    for(int i=0; i<A.size(); i++){
        num += A[i] / length - (A[i] % length == 0);
    }
    
    return num;
}

int main(){
    long long N, K;
    std::cin >> N >> K;
    A.resize(N);
    for(int i=0; i<N; i++){
        std::cin >> A[i];
    }
    
    int min = 0;
    int max = 1e9;
    
    while(max - min > 1){
        int mid = min + (max - min) / 2;
        
        long long cut_num = cut_num_calc(mid);
        if(cut_num > K){
            min = mid;
        }else{
            max = mid;
        }
    }
    
    std::cout << max << std::endl;
    
    return 0;
    
}
