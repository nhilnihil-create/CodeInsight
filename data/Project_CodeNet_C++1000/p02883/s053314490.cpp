#include <bits/stdc++.h>

int main(){
    int N;
    long long K;
    std::cin >> N >> K;
    std::vector< int > A(N);
    std::vector< int > F(N);
    long long total = 0;
    for(int i=0; i<N; i++){
        std::cin >> A[i];
        total += A[i];
    }
    for(int i=0; i<N; i++){
        std::cin >> F[i];
    }
    if(K >= total){
        std::cout << 0 << std::endl;
        return 0;
    }
    
    std::sort(A.begin(), A.end());
    std::sort(F.begin(), F.end(), std::greater<int>() );
    
    long long min = 0;
    long long max = 1e12;
    while(min != max - 1){
        long long mid = (min + max) / 2;
        long long cnt = 0;
        for(int i=0; i<N; i++){
            long long tmp = A[i] - mid / F[i];
            if(tmp > 0){
                cnt += tmp;
            }
        }
        if(K >= cnt){
            max = mid;
        }else{
            min = mid;
        }
    }
    
    std::cout << max << std::endl;
    
    return 0;
}

