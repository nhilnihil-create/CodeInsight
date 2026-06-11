#include <iostream>
int main(){
    int r,c,j,k;
    std::cin >> r >> c;
    int gyouretu[r+1][c+1] = {0};
    gyouretu[0][c] = 0;
    j = 0;
    k = 0;
    int A = 2 * c + 2;
    for(int a = 0;a < r;a++){
        for(int b = 0;b < c;b++){
            std::cin >>gyouretu[a][b];
        }
    }
    for(int d = 0;d < r;d++){
        for(int e = 0;e < c;e++){
            j = j + gyouretu[d][e];
        }
        gyouretu[d][c] = j;
        j = 0;
    }
    for(int f = 0;f < c + 1;f++){
        for(int g = 0;g < r;g++){
            k = gyouretu[g][f] + k;
        }
        gyouretu[r][f] = k;
        k = 0;
    }
    for(int h = 0;h < r + 1;h++){
        for(int i = 0;i < c + 1;i++){
            if(i < c){
            std::cout << gyouretu[h][i] <<" ";
            }else{
                std::cout <<gyouretu[h][i];
            }
        }
        std::cout << std::endl;
    }
}