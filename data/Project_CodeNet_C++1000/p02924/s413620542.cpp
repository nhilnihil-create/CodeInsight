#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep2(i,a,n) for(int i = (a);i < (n);i++)
#define rep(i,n) rep2(i,0,n)

int main(void){
    int n;cin >> n;
    
    ll alina = 0;
    for(ll i = 1;i <= n;i++)alina += i;
    
    cout << alina - n << endl;
}