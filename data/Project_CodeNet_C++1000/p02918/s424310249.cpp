#include <bits/stdc++.h>

int main(){
    int N, K;
    std::string S;
    std::cin >> N >> K >>S;
    
    int cnt = 1;
    int init_happy = 0;
    int cont = 0;
    char cur = 'N';
    for(int i=0; i<N; i++){
        if(S[i] == cur){
            cnt++;
            
        }else{
            cont++;
            cur = S[i];
            init_happy += cnt - 1;
            cnt = 1;
        }
    }
    init_happy += cnt - 1;
    
    if(cont <= 2 * K){
        std::cout << N - 1 << std::endl;
    }else{
        std::cout << init_happy + 2 * K << std::endl;
    }
    
    return 0;
}

