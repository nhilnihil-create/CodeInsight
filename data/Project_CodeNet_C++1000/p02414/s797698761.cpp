#include <iostream>
int main(){
    int n,m,l;
    long int t;
    std::cin >> n >> m >>l;
    long int A [n][m]={0},B [m][l]={0};
    long int C [n][l]={0};
    for(int a = 0;a < n;a++){
        for(int b = 0;b < m;b++){
            std::cin >> A[a][b];
        }
    }
    for(int c = 0;c < m;c++){
        for(int d = 0;d < l;d++){
            std::cin >>B[c][d];
        }
    }
    for(int e = 0;e < l;e++){
        for(int g = 0;g < n;g++){
            t = 0;
            for(int f = 0;f < m;f++){
                t = A[g][f] * B[f][e] + t;
            }
            C[g][e] = t;
        }
    }
    for(int h = 0;h<n;h++){
        for(int i = 0;i < l;i++){
            if(i <l-1){
                std::cout << C[h][i]<<" ";
            }
            if(i == l-1){
                std::cout << C[h][i];
            }
        }
        std::cout <<std::endl;
    }
}