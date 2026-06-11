#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using p = pair<int,int>;
const long long inf = 1000000001; // const 書き換え禁止
const double PI = 3.14159265358979323846; //M_PI はライブラリ


int main(void){
    int bingo[3][3];
    rep(i,3){
        rep(j,3){
            cin >> bingo[i][j];
        }
    }
    int n;
    cin >> n;
    int b[n];
    rep(i,n){
        cin >> b[i];
    }

    bool appear[3][3];
    rep(i,n){
        rep(j,n){
            appear[i][j] = false;
            rep(k,n){
                if(bingo[i][j] == b[k]){
                    appear[i][j] = true;
                }
            }
        }
    }

    string ans = "No";
    //行でのビンゴになっているかどうか
    rep(i,3){
        if(appear[0][i] && appear[1][i] && appear[2][i]){
            ans = "Yes";
        }
    }
    //列でのビンゴになっているかどうか
    rep(i,3){
        if(appear[i][0] && appear[i][1] && appear[i][2]){
            ans = "Yes";
        }
    }
    //斜めでのビンゴの判定
    if(appear[0][0] && appear[1][1] && appear[2][2]){
        ans = "Yes";
    }
    if(appear[0][2] && appear[1][1] && appear[2][0]){
        ans = "Yes";
    }
    cout << ans << endl;
}