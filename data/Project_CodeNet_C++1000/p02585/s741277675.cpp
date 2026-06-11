#include <bits/stdc++.h>

int main(){
    int N, K;
    std::cin >> N >> K;
    std::vector< int > P(N);
    std::vector< int > C(N);
    for(int i=0; i<N; i++){
        std::cin >> P[i];
        P[i]--;
    }
    for(int i=0; i<N; i++){
        std::cin >> C[i];
    }
    
    long long max = -1e18;
    
    for(int i=0; i<N; i++){
        int cnt = 1;
        int index = P[i];
        long long score = C[i];
        long long max_score = C[i];
        while(i != index && cnt < K){
            score += C[index];
            if(max_score < score){
                max_score = score;
            }
            index = P[index];
            cnt++;
        }
        if(i == index){
            if(score > 0){
                int loop_N = K / cnt - (K % cnt == 0) - 1;
                if(loop_N > 0){
                    score = score * loop_N;
                    cnt = cnt * loop_N;
                    if(max_score < score){
                        max_score = score;
                    }
                }
                while(cnt < K){
                    score += C[index];
                    if(max_score < score){
                        max_score = score;
                    }
                    index = P[index];
                    cnt++;
                }
            }
        }
        
        if(max < max_score){
            max = max_score;
        }
    }
    
    
    std::cout << max << std::endl;
    
    
    return 0;
    
}
