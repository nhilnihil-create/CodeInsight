#include <bits/stdc++.h>
// #include<iostream>
// #include<vector>
// #include<cmath>
// #include<iomanip>
using namespace std;

const double PI= acos(-1.0);

int gcd_func(int a, int b){
    return b? gcd_func(b, a%b) : a;
} 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    long long x,y; cin >> x >> y;
    long long ns = (y - 2*x)/2;
    if(ns*2 != (y-2*x)){
        cout << "No";
        return 0;
    }
    long long res = ns*4 + (x-ns)*2;
    if(ns < 0 || x - ns < 0){
        cout << "No";
        return 0;
    }
    cout << "Yes";
    return 0;
}