#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

char s[105][105];
int ans[105][105];

int main() {
    int H, W; cin >> H >> W;
    rep(i, H){
        rep(j, W){
            cin >> s[i][j];
        }
    }

    if(s[0][0] == '.'){
        ans[0][0] = 0;
    } else {
        ans[0][0] = 1;
    }

    for (int j = 1; j < W; j++){
        if(s[0][j-1] == '.' && s[0][j] == '#'){
            ans[0][j] = ans[0][j-1] + 1;
        } else {
            ans[0][j] = ans[0][j-1];
        }
    }

    for (int j = 1; j < H; j++){
        if(s[j-1][0] == '.' && s[j][0] == '#'){
            ans[j][0] = ans[j-1][0] + 1;
        } else {
            ans[j][0] = ans[j-1][0];
        }
    }

    for (int i = 1; i < H; i++){
        for (int j = 1; j < W; j++){
            int kouho1;
            if(s[i-1][j] == '.' && s[i][j] == '#'){
                kouho1 = ans[i-1][j] + 1;
            } else {
                kouho1 = ans[i-1][j];
            }
            int kouho2;
            if(s[i][j-1] == '.' && s[i][j] == '#'){
                kouho2 = ans[i][j-1] + 1;
            } else {
                kouho2 = ans[i][j-1];
            }

            ans[i][j] = min(kouho1, kouho2);
        }
    }

    cout << ans[H-1][W-1] << endl;

    return 0;
}