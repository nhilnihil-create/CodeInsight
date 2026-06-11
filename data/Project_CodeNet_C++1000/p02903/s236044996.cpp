/*
    アリナ・グレイはかわいい
*/

#include<bits/stdc++.h>
using namespace std;
#define itn int

int main(void){
    int h,w,a,b;
    cin >> h >> w >> a >> b;
    int H[1001] = {},W[1001] = {};
    
    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
            if(H[i] < w-a){
                if(W[j] < h-b){
                    cout << 0;
                    H[i]++,W[j]++;
                }
                else cout << 1;
            } else cout << 1;
        }
        cout << endl;
    }
}