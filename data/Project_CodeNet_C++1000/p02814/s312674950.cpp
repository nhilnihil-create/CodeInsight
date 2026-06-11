#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

//繰り返し二乗法
ll EX(ll x,ll n){
    if(n == 0) return 1;
    else if(n%2 == 1) return EX(x,n-1)*x;
    else return EX(x*x,n/2);
};

//ユークリッドの互除法
ll gcd(ll x,ll y){
    if(x > y) swap(x,y);
    if(x == 0) return y;
    return gcd(x,y%x);
}
//最小公倍数
ll lcm(ll x,ll y){
    return x*y/gcd(x,y);
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int cnt2 = 0;
    int tmp = a[0];
    while(tmp%2 == 0){
        if(tmp == 0) break;
        tmp /= 2;
        cnt2++;
    }

    bool end = false;
    for(int i = 0; i < n; i++){
        if(a[i]%EX(2,cnt2) != 0) end = true;
        else if(a[i]%EX(2,cnt2+1) == 0) end = true;
        if(end){
            cout << 0 << endl;
            return 0;
        }
    }
    for(int i = 0; i < n; i++) a[i] /= 2;
    ll x = 1;
    for(int i = 0; i < n; i++){
        x = lcm(x,a[i]);
        if(x > m) break;
    }
    int k = m/x;
    cout << (k+1)/2 << endl;
    return 0;
}