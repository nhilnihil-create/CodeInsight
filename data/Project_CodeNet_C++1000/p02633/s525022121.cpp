#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

//ユークリッドの互除法
ll gcd(ll x,ll y){
    if(x > y) swap(x,y);
    if(x == 0) return y;
    return gcd(x,y%x);
};

int main(){
    int x;
    cin >> x;
    if(gcd(360,x) == 1) cout << 360 << endl;
    else cout << 360/gcd(360,x) << endl; 
    return 0;
}