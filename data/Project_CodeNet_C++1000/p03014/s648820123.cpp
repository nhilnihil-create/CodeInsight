#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, w; cin >> h >> w;
    vector<vector<char>> mp(h, vector<char> (w));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mp[i][j];
        }
    }
    int L[h][w], R[h][w], U[h][w], D[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(mp[i][j] == '#') L[i][j] = 0;
            else if (j == 0) L[i][j] = 1;
            else L[i][j] = L[i][j - 1] + 1;

            if(mp[i][j] == '#') U[i][j] = 0;
            else if (i == 0) U[i][j] = 1;
            else U[i][j] = U[i - 1][j] + 1;

            if(mp[i][w-1-j] == '#') R[i][w-1-j] = 0;
            else if (j == 0) R[i][w-1-j] = 1;
            else R[i][w-1-j] = R[i][w-j] + 1;

            if(mp[h-1-i][j] == '#') D[h-1-i][j] = 0;
            else if (i == 0) D[h-1-i][j] = 1;
            else D[h-1-i][j] = D[h-i][j] + 1;
        }
    }
    int ans = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            //cout << L[i][j] << R[i][j] << U[i][j] << D[i][j] << endl;
            ans = max(ans, L[i][j] + R[i][j] + U[i][j] + D[i][j] - 3);
        }
        //cout << endl;
    }
    cout << ans << endl;
}