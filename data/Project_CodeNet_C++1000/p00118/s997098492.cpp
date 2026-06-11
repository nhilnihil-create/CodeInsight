#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>
#include <string>
#include <iostream>
#include <string.h>
#include <map>
#include <set>
#include <functional>

using namespace std;

const int INF = (1<<30) - 1;

int H, W;
int dh[] = {0, 0, 1, -1};
int dw[] = {1, -1, 0, 0};

void dfs(vector<string>& field, int h, int w){
    char c = field[h][w];
    field[h][w] = '.';
    for(int i=0; i<4; i++){
        int nh = h + dh[i];
        int nw = w + dw[i];
        if(0<=nh&&nh<H && 0<=nw&&nw<W && c == field[nh][nw])
            dfs(field, nh, nw);
    }
}

int main(){
	ios::sync_with_stdio(false);
    while(cin >> H >> W, H|W){
        vector<string> field(H);
        for(int i=0; i<H; i++)
            cin >> field[i];
        
        int ans = 0;
        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                if(field[i][j] != '.'){
                    dfs(field, i, j);
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
	return 0;
}