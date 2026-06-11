#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main(){
    long long H, W;
    cin >> H >> W;
    vector<string> S(H);
    for(int i = 0; i < H; i++) cin >> S[i];
    vector<int> sumg[H], sumr[W];
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(S[i][j] == '#') sumg[i].push_back(j);
        }
    }
    for(int i = 0; i < W; i++){
        for(int j = 0; j < H; j++){
            if(S[j][i] == '#') sumr[i].push_back(j);
        }
    }
    int ans = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(S[i][j] == '.'){
                int res = 0;
                if(sumg[i].size() == 0) res += W;
                else{
                    int indg = lower_bound(sumg[i].begin(), sumg[i].end(), j) - sumg[i].begin();
                    if(indg == 0) res += sumg[i][indg];
                    else if(indg == sumg[i].size()) res += W - 1 - sumg[i][indg - 1];
                    else res += sumg[i][indg] - sumg[i][indg - 1] - 1;
                }
                if(sumr[j].size() == 0) res += H;
                else{
                    int indr = lower_bound(sumr[j].begin(), sumr[j].end(), i) - sumr[j].begin();
                    if(indr == 0) res += sumr[j][indr];
                    else if(indr == sumr[j].size()) res += H - 1 - sumr[j][indr - 1];
                    else res += sumr[j][indr] - sumr[j][indr - 1] - 1;
                }
                res--;
                ans = max(ans, res);
            }
        }
    }
    cout << ans << endl;
}
