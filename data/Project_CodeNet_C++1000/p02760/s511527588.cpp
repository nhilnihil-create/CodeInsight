#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    vector<vector<int>> a(3, vector<int>(3));
    vector<vector<int>> ans(3, vector<int>(3));
    rep(i,3) rep(j,3) cin >> a[i][j];
    int n;
    cin >> n;
    vector<int> b(n);
    rep(i,n) cin >> b[i];
    for(int x : b){
        rep(i,3){
            rep(j,3){
                if(x == a[i][j]) ans[i][j]++;
            }
        }
    }
    bool bingo = false;
    if(ans[0][0] == 1 && ans[1][1] == 1 && ans[2][2] == 1) bingo = true;
    if(ans[0][2] == 1 && ans[1][1] == 1 && ans[2][0] == 1) bingo = true;

    rep(i,3){
        if(ans[0][i] == 1 && ans[1][i] == 1 && ans[2][i] == 1) bingo = true;
    }
    rep(i,3){
        if(ans[i][0] == 1 && ans[i][1] == 1 && ans[i][2] == 1) bingo = true;
    }
    // rep(i,3){
    //     rep(j,3){
    //         cout << ans[i][j];
    //     }
    //     cout << endl;
    // }
    if(bingo) cout << "Yes" << endl;
    else cout<< "No" << endl;
    return 0;
}