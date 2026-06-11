#include <bits/stdc++.h>

int main(){
    int N;
    std::cin >> N;
    std::vector< int > A(N);
    for(int i=0; i<N; i++){
        std::cin >> A[i];
    }
    
    std::vector< bool > b(N, false);
    std::vector< bool > s(N, false);
    
    int best = 1e9;
    bool up = false;
    for(int i=0; i<N; i++){
        if(!up && best > A[i]){
            best = A[i];
        }else if(!up && best < A[i]){
            b[i-1] = true;
            up = true;
            best = A[i];
        }else if(up && best < A[i]){
            best = A[i];
        }else if(up && best > A[i]){
            s[i-1] = true;
            up = false;
            best = A[i];
        }
    }
    if(up){
        s[N-1] = true;
    }
    
    int buy;
    long long money = 1000;
    for(int i=0; i<N; i++){
        if(b[i]){
            buy = A[i];
        }else if(s[i]){
            money = (money / buy) * A[i] + (money % buy);
        }
    }
    
    std::cout << money << std::endl;
    
    
    return 0;
    
}
