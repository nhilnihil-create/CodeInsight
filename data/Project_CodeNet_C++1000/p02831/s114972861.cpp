#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(int x,int y){
    while(y != 0){
        ll tmp = y;
        y = x % tmp;
        x = tmp;
    }
    return x;
}

int main(){
    ll a,b,g;
    cin >> a >> b;
    if(a<b){
        g = gcd(b,a);
    }else{
        g = gcd(a,b);
    }
    cout << a * b / (g) << endl;
}