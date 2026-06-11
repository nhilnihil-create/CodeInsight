#include <bits/stdc++.h>

int main(){
    int H, W;
    std::cin >> H >> W;
    std::vector< std::string > S(H);
    for(int i=0; i<H; i++){
        std::cin >> S[i];
    }
    
    std::vector< std::vector< int > > H_continue(H, std::vector< int >(W));
    std::vector< std::vector< int > > W_continue(H, std::vector< int >(W));
    
    for(int i=0; i<H; i++){
        int c = 0;
        int index = 0;
        for(int j=0; j<W; j++){
            if(S[i][j] == '#'){
                for(int k=index; k<j; k++){
                    H_continue[i][k] = c;
                }
                H_continue[i][j] = 0;
                c = 0;
                index = j + 1;
            }else{
                if(j == W - 1){
                    c++;
                    for(int k=index; k<=j; k++){
                        H_continue[i][k] = c;
                    }
                }else{
                    c++;
                }
            }
        }
    }
    
    for(int j=0; j<W; j++){
        int c = 0;
        int index = 0;
        for(int i=0; i<H; i++){
            if(S[i][j] == '#'){
                for(int k=index; k<i; k++){
                    W_continue[k][j] = c;
                }
                W_continue[i][j] = 0;
                c = 0;
                index = i + 1;
            }else{
                if(i == H - 1){
                    c++;
                    for(int k=index; k<=i; k++){
                        W_continue[k][j] = c;
                    }
                }else{
                    c++;
                }
            }
        }
    }
    
    int max = 0;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(max < H_continue[i][j] + W_continue[i][j] - 1){
                max = H_continue[i][j] + W_continue[i][j] - 1;
            }
        }
    }
    std::cout << max << std::endl;
    
    return 0;
}

