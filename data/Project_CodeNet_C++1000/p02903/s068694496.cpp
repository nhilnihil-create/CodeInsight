#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;
const int INF = 1e8;

int H, W, A, B;
vector<vector<int>> ans(1010, vector<int>(1010, 9));

int main(){
    cin >> H >> W >> A >> B;

    rep(y,H){
        rep(x,W){
            if((x<A && y<B) || (x>=A && y>=B)) ans[y][x] = 1;
            else ans[y][x] = 0;
        }
    }

    rep(y,H){
        rep(x,W){
            cout << ans[y][x];
        }
        cout << endl;
    }
}
