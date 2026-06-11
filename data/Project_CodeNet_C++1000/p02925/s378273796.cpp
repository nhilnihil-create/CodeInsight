#include <bits/stdc++.h>

int main(){
    int N;
    std::cin >> N;
    std::vector< std::deque< int > > A(N);
    std::deque< int > cur;
    for(int i=0; i<N; i++){
        cur.push_back(i);
        for(int j=0; j<N-1; j++){
            int tmp;
            std::cin >> tmp;
            A[i].push_back(tmp - 1);
        }
    }
    
    int total = N * (N - 1);
    int day = 0;
    while(total != 0){
        std::set< int > next;
        while(!cur.empty()){
            int No = cur[0];
            cur.pop_front();
            
            if(A[No].size() != 0 && A[A[No][0]].size() != 0 && A[A[No][0]][0] == No){
                next.insert(No);
                next.insert(A[No][0]);
            }
        }
        if(next.size() == 0){
             std::cout << -1 << std::endl;
            return 0;
        }
        
        for(auto itr = next.begin(); itr != next.end(); itr++){
            A[*itr].pop_front();
            total--;
            cur.push_back(*itr);
        }
        day++;
    }
    
    
    std::cout << day << std::endl;
    
    return 0;
}

