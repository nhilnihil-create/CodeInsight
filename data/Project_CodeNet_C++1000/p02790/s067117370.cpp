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
    string a, b;
    cin >> a >> b;
    int num1, num2;
    istringstream ss;
    ss = istringstream(a);
    ss >> num1;
    ss = istringstream(b);
    ss >> num2;
    string bb, aa;
    rep(i, num1){bb += b;}
    rep(i, num2){aa += a;}
    if(aa > bb){cout << bb << endl;}
    else{cout << aa << endl;}
}