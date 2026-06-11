#include <bits/stdc++.h>

int main(){
    int A, B, C, K;
    std::cin >> A >> B >> C >> K;
    
    bool ok = false;
    for(int i=0; i<K; i++){
        if(B <= A){
            B *= 2;
        }else if(C <= B){
            C *= 2;
        }
        
        if(B > A && C > B){
            ok = true;
            break;
        }
    }
    
    if(ok){
        std::cout << "Yes" << std::endl;
    }else{
        std::cout << "No" << std::endl;
    }
    
    
    return 0;
    
}
