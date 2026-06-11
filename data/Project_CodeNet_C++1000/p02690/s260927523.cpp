
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;


//x^5-1 = (x^4+x^3+x^2+x+1)(x-1)
//a^5-b^5のaを固定した時に差が一番小さくなるのはb-a-1のとき
//このときa^5-b^5は(a^4+a^3b+a^2b^2+ab^3+b^4)になる
//ここでa^4が出てくるため10^9の4乗根までのaを見れば良い
int main(){
    ll x;
    cin >> x;
    for(int a=1; a<1000; a++){
        ll a5=1;
        rep(i,5) a5 *= a;
        for(int b=-1000; b<1000; b++){
            ll b5=1;
            rep(i,5) b5 *= b;
            if(a5-b5 == x){
                printf("%d %d\n",a,b);
                return 0;
            }
        }
    }


   

}