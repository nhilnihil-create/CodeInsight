#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1000000;
const int MOD = 1000000007;

ll fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void cominit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
ll comb(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
    int x, y;
    cin >> x >> y;

    int cou_x = 0;
    int cou_y = 0;
    int flag = 0;
    ll ans = 0;
    cominit();
    if(x >= y){
        cou_x = x / 2;
        cou_y = 0;
        if(x % 2 != 0){
            cou_y++;
        }

        while(1){
            if(cou_x + cou_y * 2 == y){
                break;
            }else if(cou_x + cou_y * 2 > y){
                flag = -1;
                break;
            }else{
                cou_x--;
                cou_y += 2;
            }
        }

        if(flag == 0){
            if(cou_x <= cou_y){
                ans = comb(cou_x + cou_y, cou_x);
            }else{
                ans = comb(cou_x + cou_y, cou_y);
            }
        }
    }else{
        cou_y = y / 2;
        cou_x = 0;
        if(y % 2 != 0){
            cou_x++;
        }

        while(1){
            if(cou_x * 2 + cou_y == x){
                break;
            }else if(cou_x * 2 + cou_y > x){
                flag = -1;
                break;
            }else{
                cou_y--;
                cou_x += 2;
            }
        }

        if(flag == 0){
            if(cou_x <= cou_y){
                ans = comb(cou_x + cou_y, cou_x);
            }else{
                ans = comb(cou_x + cou_y, cou_y);
            }
        }
    }

    cout << ans << endl;
}