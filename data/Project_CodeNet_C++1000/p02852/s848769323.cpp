#include <bits/stdc++.h>

std::vector< int > route;
int N, M;
std::string S;

bool routefind(int pos){
    if(pos < 0){
        return false;
    }else if(S[pos] == '1'){
        return false;
    }else if(pos == 0){
        return true;
    }else{
        for(int i=M; i>0; i--){
            int tmp = routefind(pos - i);
            if(tmp){
                route.push_back(i);
                return true;
            }
        }
    }
    return false;
}

int main(){
    std::cin >> N >> M >> S;
    
    int continuous = 0;
    for(int i=0; i<=S.size(); i++){
        if(S[i] == '1'){
            continuous++;
            if(continuous == M){
                std::cout << -1 << std::endl;
                return 0;
            }
        }else{
            continuous = 0;
        }
    }
    
    bool tmp = routefind(N);
    
    for(int i=0; i<route.size()-1; i++){
        std::cout << route[i] << " ";
    }
    std::cout << route[route.size()-1] << std::endl;
    
    
    return 0;
    
}
