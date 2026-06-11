#include<bits/stdc++.h>
using namespace std;
int main(){
	long int a,b,c,d,prod;
	cin >> a >> b >> c >> d;
	prod = a * c;
	if(b*d > prod)
		prod = b*d;
	if(a*d > prod)
		prod = a * d;
	if(b*c > prod)
		prod = b*c;		
	cout <<	prod << endl;		
}