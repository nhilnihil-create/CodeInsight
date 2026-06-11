#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

long long ck_mandis(vector<long long> p1, vector<long long>p2);

int main(){
    long long N, X, Y, ans, w, z;
    long long w_min, w_max, z_min, z_max;
    long long X_min, i_x_min = 0, X_max, i_x_max = 0;
    std::cin >> N;
    vector<vector<long long>> points(N);

    for(long long i = 0; i < N; i++){
        std::cin >> X >> Y;
        w = X + Y;
        z = X - Y;
        if(i == 0){
            w_max = w;
            w_min = w;
            z_max = z;
            z_min = z;
        }

        if(z < z_min){
            z_min = z;
        }else if(z > z_max){
            z_max = z;
        }
        if(w < w_min){
            w_min = w;
        }else if(w > w_max){
            w_max = w;
        }
    }
    if(z_max - z_min > w_max - w_min){
        ans = z_max - z_min;
    }else{
        ans = w_max - w_min;
    }

    std::cout << ans;

}

long long ck_mandis(vector<long long> p1, vector<long long>p2){
    long long ans;
    // std::cout << "ck\n";
    // std::cout << p1[0] << " " << p1[1] << "\n"; 
    // std::cout << p2[0] << " " << p2[1] << "\n";
    ans = labs(p1[0]-p2[0]) + labs(p1[1] - p2[1]);
    // std::cout << ans << "\n";
    return ans;

}