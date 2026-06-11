#include <bits/stdc++.h>
using namespace std;
int main(){
	int a, b, c, k;
	cin >> a >> b >> c >> k;
	int z=0, y=0, x=0;
	if(k-a<0){
		x=k;
		k=0;
	}
	else{
		x=a;
		k-=a;	
	}
	if(k-b<0){
		y=k;
		k=0;
	}
	else{
		y=b;
		k-=b;
	}
	if(k-c<0){
		z=k;
		k=0;
	}
	else{
		z=c;
	}
	cout << x*1+y*0+z*(-1);
}
