#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> field(H);
    vector<vector<int> > memo(H, vector<int>(W, -1));
    for(int h=0; h<H; h++) {
        cin >> field[h];
        if(h==0) {
            if(field[h][0]=='.') {
                memo[h][0] = 0;
            } else {
                memo[h][0] = 1;
            }
            for(int w=1; w<W; w++) {
                memo[h][w] = memo[h][w-1];
                if(field[h][w-1]=='.' && field[h][w]=='#') {
                    memo[h][w]++;
                }
            }
        } else {
            memo[h][0] = memo[h-1][0];
            if(field[h-1][0]=='.' && field[h][0]=='#') {
                memo[h][0]++;
            }
            for(int w=1; w<W; w++) {
                int u=memo[h-1][w], l=memo[h][w-1];
                if(field[h-1][w]=='.' && field[h][w]=='#') {
                    u++;
                }
                if(field[h][w-1]=='.' && field[h][w]=='#') {
                    l++;
                }
                memo[h][w] = min(u, l);
            }
        }
    }
    cout << memo[H-1][W-1] << endl;




    return 0;
    
}