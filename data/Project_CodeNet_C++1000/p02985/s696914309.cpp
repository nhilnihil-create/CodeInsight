#include <bits/stdc++.h>

int mod = 1e9 + 7;

int main(){
    int N, K;
    std::cin >> N >> K;
    std::vector< std::vector< int > > AB(N);
    for(int i=0; i<N-1; i++){
        int a, b;
        std::cin >> a >> b;
        AB[a - 1].push_back(b - 1);
        AB[b - 1].push_back(a - 1);
    }
    
    int st = 0;
    for(int i=0; i<N; i++){
        if(AB[i].size() == 1){
            st = i;
            break;
        }
    }
    
    std::deque< int > deq_No;
    std::deque< int > deq_preNo;
    std::deque< int > deq_color;
    std::deque< int > deq_d;
    deq_No.push_back(st);
    deq_preNo.push_back(-1);
    deq_color.push_back(0);
    deq_d.push_back(0);
    
    long long ans = 1;
    
    while(!deq_No.empty()){
        int No = deq_No[0];
        int preNo = deq_preNo[0];
        int color = deq_color[0];
        int d = deq_d[0];
        deq_No.pop_front();
        deq_preNo.pop_front();
        deq_color.pop_front();
        deq_d.pop_front();
        
        ans = (ans * (K - color - (d >= 2))) % mod;
        
        int cnt = 1;
        for(int i=0; i<AB[No].size(); i++){
            if(AB[No][i] == preNo){
                continue;
            }
            deq_No.push_back(AB[No][i]);
            deq_preNo.push_back(No);
            deq_color.push_back(cnt);
            deq_d.push_back(d + 1);
            cnt++;
        }
    }
    
    std::cout << ans << std::endl;
    
    return 0;
}

