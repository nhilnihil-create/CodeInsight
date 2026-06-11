#include<bits/stdc++.h>
using namespace std;

int H, W, K;

int main(){
    int ans = 0;
    char buf;
    cin >> H >> W >> K;
    int N = 0;
    vector<vector<int>> C(H, vector<int>(W, 0));
    for(int h = 0; h < H; ++h){
        for(int w = 0; w < W; ++w){
            cin >> buf;
            if(buf == '#'){
                C[h][w] = 1;
                ++N;
            }
        }
    }
    for(int i = 0; i < pow(2,H); ++i){
        for(int j = 0; j < pow(2,W); ++j){
            int n = N;
            for(int h = 0; h < H; ++h){
                for(int w = 0; w < W; ++w){
                    if( C[h][w] && ( ((i>>h) & 1) || ((j>>w) & 1) ) ) --n; //(i,j)成分は赤色。
                }
            }
            if(n == K) ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}