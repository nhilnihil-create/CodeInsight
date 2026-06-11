#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int fun(int N, int A[]){
    
    for (int i = 0; i < 12; i++){
        if (N % 2 == 0){
            A[i] = 0;
        } else {
            A[i] = 1;
        }
        
        N /= 2;
    }
    
    return 0;
}

int main(){
    
    int i, j, k, H, W, K, count, sum, ans;
    cin >> H >> W >> K;
    count = 0;
    sum = 0;
    ans = 0;
    
    int C[H][W], D[H][W];
    
    int A[12] = {};
    
    char ddd;
    
    for (i = 0; i < H; i++){
        for (j = 0; j < W; j++){
            
            cin >> ddd;
            if (ddd == '.'){
                C[i][j] = 0; //白
            } else if (ddd == '#'){
                C[i][j] = 1; //黒
            } else {
                
            }
        }
    }
        
    for (i = 0; i < int(pow(2, H + W)); i++){
        
        for (int x = 0; x < H; x++){
            for (int y = 0; y < W; y++){
                D[x][y] = C[x][y];
            }
        }
        
        fun(i, A);
        
        for (j = 0; j < H; j++){
            
            if (A[j] == 1){
                for (k = 0; k < W; k++){
                    D[j][k] = 0;
                }
            }
        }
        
        for (j = H; j < H + W; j++){
            
            if (A[j] == 1){
                for (k = 0; k < H; k++){
                    D[k][j - H] = 0;
                }
            }
        }
        
        count = 0;
        
        for (int x = 0; x < H; x++){
            for (int y = 0; y < W; y++){
                
                if (D[x][y] == 1) count++;
            }
        }
        
        if (count == K) ans++;
        
    }
    
    cout << ans << "\n";
    
    return 0;
}


