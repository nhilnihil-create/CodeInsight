#include <bits/stdc++.h>
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
typedef long long ll;
using namespace std;

int main(){
    ll x;
    cin >> x;
    ll root = pow(x, 1/5);
    
    ll ans_a = 0;
    ll ans_b = 0;
    bool flg = false;
    
    rep(i, 10000){
        rep(j, 10000){
            if(x>=pow(root+i, 5)-pow(j, 5) && x<=pow(root-i, 5)-pow(-j, 5))break;
            
            if(x==pow(root+i, 5)-pow(j, 5)){
                ans_a = root+i;
                ans_b = j;
                flg = true;
            }
            if(x==pow(root+i, 5)-pow(-j, 5)){
                ans_a = root+i;
                ans_b = -j;
                flg = true;
            }
            if(x==pow(root-i, 5)-pow(j, 5)){
                ans_a = root-i;
                ans_b = j;
                flg = true;
            }
            if(x==pow(root-i, 5)-pow(-j, 5)){
                ans_a = root-i;
                ans_b = -j;
                flg = true;
            }
            if(flg)break;
        }
        if(flg)break;
    }
    
    cout << ans_a << " " << ans_b << endl;
}