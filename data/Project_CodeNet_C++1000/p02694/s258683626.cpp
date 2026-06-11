#include <bits/stdc++.h>
using namespace std;

int main(){

//int N,A,B,C,K,d,X;
unsigned long long X,N;
int C;
cin >> X;
N = 100;
C = 0;
//cin >> K >> A >> B;
//vector<int> A(N);

while(N<X){
	N += N/100;
	C++;
}
cout << C << endl;
}