#include <bits/stdc++.h>

int main(){
    int X;
    std::cin >> X;
    
    int ans;
    if(X < 600){
        ans = 8;
    }else if(X < 800){
        ans = 7;
    }else if(X < 1000){
        ans = 6;
    }else if(X < 1200){
        ans = 5;
    }else if(X < 1400){
        ans = 4;
    }else if(X < 1600){
        ans = 3;
    }else if(X < 1800){
        ans = 2;
    }else if(X < 2000){
        ans = 1;
    }
    
    std::cout << ans << std::endl;
    
    
    return 0;
    
}
