#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;
const ll MOD = 1e9 + 7;

int l[2100][2100], r[2100][2100], u[2100][2100], d[2100][2100];

int main() {
    int h, w; cin >> h >> w;
    V<string> board(h);
    for(int i = 0; i < h; i++) cin >> board[i];

    for(int i = 0; i < h; i++){
        int c = 0;
        for(int j = 0; j < w; j++){
            if(board[i][j] == '#') c = 0;
            else c++;
            l[i][j] = c;
        }
    }
    for(int i = 0; i < h; i++){
        int c = 0;
        for(int j = w - 1; j >= 0; j--){
            if(board[i][j] == '#') c = 0;
            else c++;
            r[i][j] = c;
        }
    }
    for(int i = 0; i < w; i++){
        int c = 0;
        for(int j = 0; j < h; j++){
            if(board[j][i] == '#') c = 0;
            else c++;
            u[j][i] = c;
        }
    }
    for(int i = 0; i < w; i++){
        int c = 0;
        for(int j = h - 1; j >= 0; j--){
            if(board[j][i] == '#') c = 0;
            else c++;
            d[j][i] = c;
        }
    }
    int ans = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            ans = max(ans, (l[i][j] + r[i][j] + d[i][j] + u[i][j] - 3));
        }
    }
    cout << ans << endl;

}
