#include <bits/stdc++.h>
using namespace std;

int main(){
int X,a,b,t;
cin >> X;
a = X/500;
t = X%500;
b = t/5;
cout << 1000*a+5*b << endl;
}