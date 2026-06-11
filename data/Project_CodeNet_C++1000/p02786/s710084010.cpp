#include <vector>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long ;

int min(int a,int b){
    return (a<b)? a : b ;
}

ll f(ll x){
    if(x==1) return 1 ;
    return f(x/2)*2+1 ;
}

int main() {
    ll h ;
    cin >> h ;

    cout << f(h) << endl ;
    return 0 ;
}
