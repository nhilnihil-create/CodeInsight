#include<iostream>
#include<vector>
#include<string>

using ll = long long;

int main(){
    ll W, H, x, y;
    std::cin >> W >> H >> x >> y;
    long double s = W * H * 0.5;
    int offset = 0;
    if(2 * x == W && 2 * y == H){
        offset = 1;
    }
    printf("%.10llf %d\n", s, offset);
    return 0;
}
