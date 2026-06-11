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
    
    std::vector< long long > loop_score(N);
    std::vector< int > loop_cnt(N, 0);
    long long max = -1e18;
    
    for(int i=0; i<N; i++){
        if(loop_cnt[i] == 0){
            int cnt = 1;
            int index = P[i];
            long long score = C[i];
            long long max_score = C[i];
            std::vector< int > root(1, i);
            while(i != index && cnt < K){
                score += C[index];
                if(max_score < score){
                    max_score = score;
                }
                index = P[index];
                root.push_back(index);
                cnt++;
            }
            if(i == index){
                for(int j=0; j<root.size(); j++){
                    loop_score[root[j]] = score;
                    loop_cnt[root[j]] = cnt;
                }
                
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
        }else{
            int cnt = 1;
            int index = P[i];
            long long score = C[i];
            long long max_score = C[i];
            if(loop_score[i] > 0){
                int loop_N = K / loop_cnt[i] - (K % loop_cnt[i] == 0) - 1;
                if(loop_N > 0){
                    score += loop_score[i] * loop_N;
                    cnt += loop_cnt[i] * loop_N;
                    if(max_score < score){
                        max_score = score;
                    }
                }
            }else{
                int loop_N = K / loop_cnt[i] - (K % loop_cnt[i] == 0) - 1;
                if(loop_N > 0){
                    cnt += loop_cnt[i] * loop_N;
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
            if(max < max_score){
                max = max_score;
            }
        }
    }
    
    
    std::cout << max << std::endl;
    
    
    return 0;
    
}
