#include<bits/stdc++.h>
using namespace std;

int H, W, res = 0;
vector<string> Grid_c(2010);
vector<vector<int>> Grid_i(2010, vector<int>(2010, 0));


void seri_Row(void){
    for(int i = 0; i < H; i++){
        int j = 0;
        while(j < W){
            int k = 0;
            while(j+k < W && Grid_c[i][j+k] != '#') ++k;
            for(int l = j; l < j+k; l++) Grid_i[i][l] += k;
            j += k+1;
        }
    }
    return ;
}



void seri_Column(void){
    for(int i = 0; i < W; i++){
        int j = 0;
        while(j < H){
            int k = 0;
            while(j+k < H && Grid_c[j+k][i] != '#') ++k;
            for(int l = j; l < j+k; l++) Grid_i[l][i] += k;
            j += k+1;
        }
    }
    return ;
}



int main(){
    cin >> H >> W;
    for(int i = 0; i < H; i++) cin >> Grid_c[i];

    seri_Row();
    seri_Column();
  

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++) res = max(res, Grid_i[i][j]-1);
    }

    cout << res << endl;
    return 0;
}