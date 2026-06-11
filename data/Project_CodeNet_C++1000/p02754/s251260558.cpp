#include <iostream>
#include<stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n,a,b,x,y,res;
    cin >> n>>a>>b;
    x = n/(a+b);
    y = n%(a+b);
    res = x*a;
    if(y>a)res+=a;
    else res += y;

    cout << res <<endl;
    
}