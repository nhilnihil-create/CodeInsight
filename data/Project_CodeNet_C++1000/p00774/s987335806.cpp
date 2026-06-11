#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
using namespace std;
int mod = 1000000007;

int main(void){
    //消えるたびに上から落としていけばいい
    int H;
    while(true){
        cin >> H;
        if(H == 0) break;
        vector<vector<int>> grid(H);
        rep(i, H) grid[i].resize(5);
        rep(i, H) rep(j, 5) cin >> grid[i][j];
        bool cont = true;
        int score = 0;
        while(cont){
            cont = false;
            rep(i, H){
                rep(j, 3){
                    if(grid[i][j] != -1 && grid[i][j] == grid[i][j+1] && grid[i][j] == grid[i][j+2]){
                        if(j <= 1 && grid[i][j] == grid[i][j+3]){
                            if(j == 0 && grid[i][j] == grid[i][j+4]){
                                score += grid[i][j]*5;
                                for(int k = i; k >= 0; k--){
                                    if(k == 0) rep(l, 5) grid[0][l] = -1;
                                    else rep(l, 5) grid[k][l] = grid[k-1][l];
                                }
                            }
                            else{
                                score += grid[i][j]*4;
                                for(int k = i; k >= 0; k--){
                                    if(k == 0) for(int l = j; l < j+4; l++) grid[0][l] = -1;
                                    else for(int l = j; l < j+4; l++) grid[k][l] = grid[k-1][l];
                                }
                            }
                        }
                        else{
                            score += grid[i][j]*3;
                            for(int k = i; k >= 0; k--){
                                if(k == 0) for(int l = j; l < j+3; l++) grid[0][l] = -1;
                                else for(int l = j; l < j+3; l++) grid[k][l] = grid[k-1][l];
                            }
                        }
                        cont = true;
                        break; //同じ行で二個以上の消滅は無い
                    }
                }
            }
        }
        cout << score << endl;
    }
    return 0;
}
