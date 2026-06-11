#include <bits/stdc++.h>
using namespace std ;
#define An setprecision(16) 
int main(){
    int A,B,C,D;
    int a;
    int b;
    cin >> A >> B >> C >> D;
    if(A%D==0)a=A/D;
    else a= A/D+1;
    if(C%B==0)b=C/B;
    else b = C/B+1;
    if(b<=a)cout << "Yes" << endl;
    else cout << "No" << endl;
}