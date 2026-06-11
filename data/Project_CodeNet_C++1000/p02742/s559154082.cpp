#include <bits/stdc++.h>
using namespace std;

int main(void){
    
    unsigned long H,W;
    cin >> H >> W;
    
    if(H%2 == 1 && W%2 == 1){
        if(H == 1 || W == 1){
            cout << 1 << endl;
        }
        else{
            cout<< H*W/2 + 1 <<endl;
        }
        
    }
    else{
        if(H == 1 || W == 1){
            cout << 1 << endl;
        }
        else{
            cout<< H*W/2 <<endl;
        }
        
    }
   
}