#include <bits/stdc++.h>

int mud_num = 1e9 + 7;

int main(){
    std::string S;
    std::cin >> S;
    
    int digit = 1;
    std::vector< int > cnt(13, 0);
    cnt[0] = 1;
    
    for(int i=S.size() - 1; i>=0; i--){
        std::vector< int > cur_cnt(13, 0);
        std::vector< int > num;
        if(S[i] == '?'){
            for(int j=0; j<10; j++){
                num.push_back(j);
            }
        }else{
            num.push_back(S[i] - '0');
        }
        
        for(int j=0; j<num.size(); j++){
            int div_re = (digit * num[j]) % 13;
            cur_cnt[div_re]++;
        }
        
        std::vector< int > new_cnt(13, 0);
        for(int a=0; a<13; a++){
            for(int b=0; b<13; b++){
                new_cnt[(a + b) % 13] = (new_cnt[(a + b) % 13] + cnt[a] * cur_cnt[b]) % mud_num;
            }
        }
        cnt = new_cnt;
        digit = (digit * 10) % 13;
    }
    
    
    std::cout << cnt[5] << std::endl;
    
    return 0;
}

