#include<bits/stdc++.h>
using namespace std;

int main(){

    long long H, W;
    cin >> H >> W;
    long long res = 0;
    long long w=0, h=0;
    
    if(W%2 == 0){
        w = W/2;
        if(H%2 == 0){
            h = H/2;
            res = w*H;
        }else{
            h = (H+1)/2;
            res = w*H;
        }
    }else{
        w = (W+1)/2;
        if(H%2 == 0){
            h = H/2;
            res = w*h + (w-1)*h;    
        }else{
            h = (H+1)/2;
            res = w*h + (w-1)*(h-1);
       }
    }
    if(H==1 || W==1){
        cout << 1 << endl;
    }else{
        cout << res << endl;
    }
    

}