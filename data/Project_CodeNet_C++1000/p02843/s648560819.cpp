#include<bits/stdc++.h>
#define ll long long 
using namespace std;

ll gcd(ll x ,ll y){
    ll r = x%y;
    if(r==0)return y;
    else return gcd(y ,r);
}

int main(){
    int x;
    cin >> x;
    int r = x % 100;
    int q = x / 100;
    if(r>q*5) cout << "0" << endl;
    else cout << "1" << endl;
}