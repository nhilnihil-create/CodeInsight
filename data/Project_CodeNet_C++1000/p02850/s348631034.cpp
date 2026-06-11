#include <bits/stdc++.h>

int main(){
    int N;
    std::cin >> N;
    std::vector< std::vector< int > > AB(N);
    std::vector< std::vector< int > > ABinNo(N);
    for(int i=0; i<N-1; i++){
        int tmp1, tmp2;
        std::cin >> tmp1 >> tmp2;
        AB[tmp1 - 1].push_back(tmp2 - 1);
        AB[tmp2 - 1].push_back(tmp1 - 1);
        ABinNo[tmp1 - 1].push_back(i);
        ABinNo[tmp2 - 1].push_back(i);
    }
    
    std::deque< int > deq_No;
    std::deque< int > deq_preNo;
    std::deque< int > deq_preColor;
    deq_No.push_back(0);
    deq_preNo.push_back(-1);
    deq_preColor.push_back(-1);
    
    std::vector< int > color_ans(N-1);
    int max = 0;
    while(!deq_No.empty()){
        int cur_No = deq_No[0];
        int cur_preNo = deq_preNo[0];
        int cur_preColor = deq_preColor[0];
        deq_No.pop_front();
        deq_preNo.pop_front();
        deq_preColor.pop_front();
        
        int color_cnt = 1;
        for(int i=0; i<AB[cur_No].size(); i++){
            if(AB[cur_No][i] == cur_preNo){
                continue;
            }
            if(color_cnt == cur_preColor){
                color_cnt++;
            }
            color_ans[ABinNo[cur_No][i]] = color_cnt;
            deq_No.push_back(AB[cur_No][i]);
            deq_preNo.push_back(cur_No);
            deq_preColor.push_back(color_cnt);
            color_cnt++;
        }
        if(max < color_cnt-1){
            max = color_cnt-1;
        }
    }
    
    std::cout << max << std::endl;
    for(int i=0; i<N-1; i++){
        std::cout << color_ans[i] << std::endl;
    }
    
    return 0;
}

