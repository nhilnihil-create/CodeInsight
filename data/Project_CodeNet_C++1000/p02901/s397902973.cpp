#include <bits/stdc++.h>

int main(){
    int N, M;
    std::cin >> N >> M;
    std::vector< int > A(M);
    std::vector< int > unlock(M, 0);
    std::vector< std::vector< int > > unlock_rev(N);
    for(int i=0; i<M; i++){
        int b;
        std::cin >> A[i] >> b;
        for(int j=0; j<b; j++){
            int c;
            std::cin >> c;
            unlock[i] += (int)std::pow(2.0, N - c);
            unlock_rev[c - 1].push_back(i);
        }
    }
    
    std::vector< int > unlock_deq(1);
    std::vector< int > cost_deq(1);
    unlock_deq[0] = 0;
    cost_deq[0] = 0;
    std::vector< int > unlock_deq_new;
    std::vector< int > cost_deq_new;
    
    for(int i=0; i<N; i++){
        
        int mask_cur = (int)std::pow(2.0, N - i - 1);
        for(int a=0; a<unlock_deq.size(); a++){
            if(unlock_deq[a] & mask_cur){
                unlock_deq_new.push_back(unlock_deq[a] % mask_cur);
                cost_deq_new.push_back(cost_deq[a]);
            }else{
                for(int b=0; b<unlock_rev[i].size(); b++){
                    unlock_deq_new.push_back( (unlock_deq[a] | unlock[unlock_rev[i][b]]) % mask_cur );
                    cost_deq_new.push_back(cost_deq[a] + A[unlock_rev[i][b]]);
                }
            }
        }
        std::vector< int > cost_deq_tmp(mask_cur, 1e9);
        for(int a=0; a<cost_deq_new.size(); a++){
            if(cost_deq_tmp[unlock_deq_new[a]] > cost_deq_new[a]){
                cost_deq_tmp[unlock_deq_new[a]] = cost_deq_new[a];
            }
        }
        
        unlock_deq_new.clear();
        cost_deq_new.clear();
        unlock_deq.clear();
        cost_deq.clear();
        for(int a=0; a<cost_deq_tmp.size(); a++){
            if(cost_deq_tmp[a] != 1e9){
                unlock_deq.push_back(a);
                cost_deq.push_back(cost_deq_tmp[a]);
            }
        }
        
    }
    
    if(cost_deq.size() == 0){
        std::cout << -1 << std::endl;
    }else{
        for(int i=0; i<cost_deq.size(); i++){
            std::cout << cost_deq[i] << std::endl;
        }
    }
    
    return 0;
}

