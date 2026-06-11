#include <bits/stdc++.h>
using namespace std;
#define int long long
using vec_int = vector<int>;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int charToInt(char c){
    char zero_num = '0';
    return (int)c - (int)zero_num;
}

vector<ll> fac(1000001); //n!(mod M)
vector<ll> ifac(1000001); //k!^{M-2} (mod M)
//a,bの範囲的にこれだけ配列を用意していけば十分

int M= pow(10,9)+7;

ll mpow(ll x, ll n){ //x^n(mod M) ←普通にpow(x,n)では溢れてしまうため，随時mod計算
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % M;
        x = x*x % M;
        n = n >> 1;
    }
    return ans;
}

ll comb(ll a, ll b){ //aCbをmod計算
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    ll tmp = ifac[a-b]* ifac[b] % M;
    return tmp * fac[a] % M;
}

signed main(){
    int X, Y; cin>>X>>Y;

    //何回ナイトを動かせばよいかを求められれば良い
    //つまり、
    // a + 2*b = X
    // 2a + b = Y
    //これから、 
    //b = (2X-Y)/3
    //a = (2Y-X)/3
    //この両方が正の整数でないと死亡
    if((2*X-Y)%3!=0 ||(2*Y-X)%3!=0){
        cout<<0<<endl;
        return 0;
    }
    int a = (2*X-Y)/3;
    int b = (2*Y-X)/3;
    if(a<0 || b<0){
        cout<<0<<endl;
        return 0;
    }

    //あとは(a+b)の長さの0と1の列のどこにa個の1を入れるかを求める問題になる。
    //つまり(a+b)Caを求めればよい。


    fac[0] = 1;
    ifac[0] = 1;
    for(ll i = 0; i<1000000; i++){
        fac[i+1] = fac[i]*(i+1) % M; // n!(mod M)
        ifac[i+1] = ifac[i]*mpow(i+1, M-2) % M; // k!^{M-2} (mod M) ←累乗にmpowを採用
    }

    ll answer = comb((a+b),a)%M;
    cout<<answer<<endl;





    return 0;
}