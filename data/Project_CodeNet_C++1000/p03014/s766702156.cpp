#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int H,W;
    cin >> H >> W;
    vector<string> vec(H);
    rep(i,H){
        cin >> vec[i];
    }
    vector<vector<int> > left(H,vector<int>(W));
    vector<vector<int> > right(H,vector<int>(W));
    vector<vector<int> > up(H,vector<int>(W));
    vector<vector<int> > down(H,vector<int>(W));
    
    
    rep(i,H){
        if (vec[i][0] == '.') left[i][0] = 1;
        else left[i][0] = 0;
        rep(j,W - 1){
            if (vec[i][j + 1] == '.') left[i][j + 1] = left[i][j] + 1;
            else left[i][j + 1] = 0;
        }
    }
    
    rep(i,H){
        if (vec[i][W - 1] == '.') right[i][W - 1] = 1;
        else right[i][W - 1] = 0;
        for (int j = W - 1; j >= 1; j--){
            if (vec[i][j - 1] == '.') right[i][j - 1] = right[i][j] + 1;
            else right[i][j - 1] = 0;
        }
    }
    
    rep(i,W){
        if (vec[0][i] == '.') up[0][i] = 1;
        else up[0][i] = 0;
        for (int j = 0; j < H - 1; j++){
            if (vec[j + 1][i] == '.') up[j + 1][i] = up[j][i] + 1;
            else up[j + 1][i] = 0;
        }
    }
    
    rep(i,W){
        if (vec[H - 1][i] == '.') down[H - 1][i] = 1;
        else down[H - 1][i] = 0;
        for (int j = H - 1; j >= 1; j--){
            if (vec[j - 1][i] == '.') down[j - 1][i] = down[j][i] + 1;
            else down[j - 1][i] = 0;
        }
    }
    
    int ans = 0;
    rep(i,H){
        rep(j,W){
            ans = max(ans, left[i][j] + right[i][j] + up[i][j] + down[i][j] - 3);
        }
    }
    cout << ans << endl;
}

