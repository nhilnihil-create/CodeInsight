#include <bits/stdc++.h>
using namespace std;

int main(){

int N,A,B,C,D,X,T;
cin >> N >> X >> T;

if(N%X==0) A = N/X;
else A = N/X+1;

cout << A*T << endl;
}