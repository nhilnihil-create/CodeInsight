#include <bits/stdc++.h>

int main(){
    int N, K;
    std::cin >> N >> K;
    std::vector< int > A;
    std::vector< int > B;
    
    int max = 0;
    
    for(int i=2; i<=N; i++){
        A.push_back(1);
        B.push_back(i);
        max += i - 2;
    }
    
    if(max < K){
        std::cout << -1 << std::endl;
        return 0;
    }else if(max > K){
        for(int i=2; i<=N; i++){
            for(int j=i+1; j<=N; j++){
                A.push_back(i);
                B.push_back(j);
                max--;
                if(max == K){
                    break;
                }
            }
            if(max == K){
                break;
            }
        }
    }
    
    std::cout << A.size() << std::endl;
    for(int i=0; i<A.size(); i++){
        std::cout << A[i] << " " << B[i] << std::endl;
    }
    
    return 0;
}

