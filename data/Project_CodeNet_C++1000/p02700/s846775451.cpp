#include<bits/stdc++.h>
using namespace std;
 int main(){
     int a,b,c,d;
     cin >> a >> b >> c >>d;
     int T=0,A=0;
    T=(c+b-1)/b;
    A=(a+d-1)/d;
    cout<<(A>=T?"Yes":"No")<<endl;
 }