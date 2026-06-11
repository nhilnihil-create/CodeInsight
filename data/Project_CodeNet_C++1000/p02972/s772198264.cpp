#include <bits/stdc++.h>

int main(){
    int N;
    std::cin >> N;
    std::vector< int > A(N);
    for(int i=0; i<N; i++){
        std::cin >> A[i];
    }
    
    std::vector< int > boll(N);
    int N_cnr = N;
    while(N_cnr != 0){
        int N_half = N_cnr / 2;
        for(int i=N_half; i<N_cnr; i++){
            int cnt = A[i];
            int cur = i * 2 + 1;
            while(cur < N){
                cnt += boll[cur];
                cur += i + 1;
            }
            boll[i] = cnt % 2;
        }
        N_cnr /= 2;
    }
    
    std::vector< int > ans;
    int ans_cnt = 0;
    for(int i=0; i<N; i++){
        if(boll[i]){
            ans_cnt++;
            ans.push_back(i + 1);
        }
    }
    std::cout << ans_cnt << std::endl;
    if(ans_cnt){
        for(int i=0; i<ans.size(); i++){
            std::cout << ans[i] << std::endl;
        }
    }
    
    return 0;
}

