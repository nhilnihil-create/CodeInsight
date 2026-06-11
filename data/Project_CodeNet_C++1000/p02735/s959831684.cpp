#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <numeric>
#include <cstdint>
#include <iomanip>
#include <set>
#include <map>
#include <unordered_map>
#include <cassert>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
    int h,w;
    std::cin >> h >> w;
    std::vector<std::string> stage(h);
    rep(i,h) std::cin >> stage[i];

    std::vector<std::vector<long long> > dp(h,std::vector<long long>(w,1145141919));
    //i,jに行くまでにかかる最小の更新数
    if(stage[0][0]=='#') dp[0][0] = 1;
    else dp[0][0] = 0;

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            //right direction
            int dx = 1, dy = 0, z;
            if(i+dx >= h || j+dy >= w){
                ;
            }else{
                if(stage[i+dx][j+dy]=='#' && stage[i][j]=='.') z=1;
                else z=0;
                chmin(dp[i+dx][j+dy], dp[i][j]+z);
            }
            //bottom direction
            dx = 0; dy = 1;
            if(i+dx >= h || j+dy >= w){
                ;
            }else{
                if(stage[i+dx][j+dy]=='#' && stage[i][j]=='.') z=1;
                else z=0;
                chmin(dp[i+dx][j+dy], dp[i][j]+z);
            }
        }
    }

    std::cout << dp[h-1][w-1] << "\n";
    return 0;
}