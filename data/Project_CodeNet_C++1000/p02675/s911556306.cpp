#include <bits/stdc++.h>
using namespace std;

int main(){
int a,b,X,T=1,N;
cin >> N;
	
a = N/100;
T = N-100*a;
b = T/10;
T = T-10*b;
if(T == 3){
	cout << "bon" << endl;
}
else if(T == 0 || T == 1|| T == 6|| T == 8){
	cout << "pon" << endl;
}
else{
	cout << "hon" << endl;
}
}