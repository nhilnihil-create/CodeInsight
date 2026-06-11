#include<bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define PI 3.14159265358979323846264338327950L
using namespace std;
using P = pair<int,int>;
using ll = long long;
using namespace std;
int main(void){
    ll h, n;
    cin >> h >> n;
    ll ans = 0;
    ll a[n]; rep(i, n){cin >> a[i]; ans += a[i];}
    if(h <= ans){cout << "Yes" << endl;}
    else{cout << "No" << endl;}
    return 0;
}