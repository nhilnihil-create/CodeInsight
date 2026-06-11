#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main(){
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for(int i = 0; i < H; i++) cin >> S[i];
    vector<vector<int>> tate(W), yoko(H);
    for(int i = 0; i < H; i++){
        yoko[i].push_back(-1);
        for(int j = 0; j < W; j++){
            if(S[i][j] == '#') yoko[i].push_back(j);
        }
        yoko[i].push_back(W);
    }
    for(int i = 0; i < W; i++){
        tate[i].push_back(-1);
        for(int j = 0; j < H; j++){
            if(S[j][i] == '#') tate[i].push_back(j);
        }
        tate[i].push_back(H);
    }
    int ans = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(S[i][j] == '.'){
                int res = 0;
                auto ite1 = lower_bound(yoko[i].begin(), yoko[i].end(), j);
                auto ite2 = lower_bound(tate[j].begin(), tate[j].end(), i);
                int r = *ite1--, l = *ite1, d = *ite2--, u = *ite2;
                res += (r - j - 1) + (j - l - 1) + (i - u - 1) + (d - i - 1) + 1;
                ans = max(ans, res);
            }
        }
    }
    cout << ans << endl;
}