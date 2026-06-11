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
   // freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    char ipt; cin >> ipt;
    if(ipt - 'A' < 26 && ipt-'A' >=0){
        cout << 'A';
    }
    else{
        cout << 'a';
    }
    return 0;
}