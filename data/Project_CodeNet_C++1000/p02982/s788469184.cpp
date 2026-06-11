#include<iostream>
#include<cmath>

int main(void){
    int n, d, ans = 0;
    std::cin >> n >> d;
    int x[n][d];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < d; j++){
            std::cin >> x[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int dist = 0;
            for(int k = 0; k < d; k++){
                dist += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
            }
            int rdist = std::sqrt(dist);
            if(rdist * rdist == dist) ans++;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}