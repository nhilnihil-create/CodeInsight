#include <bits/stdc++.h>

int main(){
    int N, M;
    std::cin >> N >> M;
    std::vector< std::vector< int > > route(N);
    for(int i=0; i<M; i++){
        int tmp1, tmp2;
        std::cin >> tmp1 >> tmp2;
        route[tmp1 - 1].push_back(tmp2 - 1);
    }
    int S, T;
    std::cin >> S >> T;
    
    std::vector< std::vector< bool > > en(3, std::vector< bool >(N, true));
    
    std::deque< int > No_deq;
    std::deque< int > move_deq;
    No_deq.push_back(S - 1);
    move_deq.push_back(0);
    
    while(!No_deq.empty()){
        int cur_No = No_deq[0];
        int cur_move = move_deq[0];
        No_deq.pop_front();
        move_deq.pop_front();
        
        if(cur_No == T - 1 && cur_move % 3 == 0){
            std::cout << cur_move / 3 << std::endl;
            return 0;
        }
        
        if(en[cur_move % 3][cur_No]){
            en[cur_move % 3][cur_No] = false;
        }else{
            continue;
        }
        
        for(int i=0; i<route[cur_No].size(); i++){
            No_deq.push_back(route[cur_No][i]);
            move_deq.push_back(cur_move + 1);
        }
    }
    
    std::cout << -1 << std::endl;
    
    return 0;
}

