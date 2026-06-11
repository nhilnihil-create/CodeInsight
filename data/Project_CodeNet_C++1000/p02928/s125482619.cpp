#include <bits/stdc++.h>

int mod_num = 1e9 + 7;

int main(){
    int N, K;
    std::cin >> N >> K;
    std::vector< int > A(N);
    for(long long i=0; i<N; i++){
        std::cin >> A[i];
    }
    
    int down = 0;
    int up = 0;
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            if(A[i] > A[j]){
                down++;
            }
        }
        for(int j=i-1; j>=0; j--){
            if(A[i] > A[j]){
                up++;
            }
        }
    }
    
    int cnt = 0;
    long long tmp = ( (long long)K * ((long long)K + 1) / (long long)2 ) % mod_num;
    tmp = (tmp * down) % mod_num;
    cnt += tmp;
    
    tmp = ( (long long)K * ((long long)K - 1) / (long long)2 ) % mod_num;
    tmp = (tmp * up) % mod_num;
    cnt += tmp;
    cnt = cnt % mod_num;
    
    std::cout << cnt << std::endl;
    
    
    return 0;
}

