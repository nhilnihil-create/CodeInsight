#include <bits/stdc++.h>
using namespace std;

int main (){
	int n,nn,i,j,p;
	cin >> n;
	nn=n;
	while(1){
		if(nn==1){
			cout << "No" << endl;
			return 0;
		}
		if((nn%2)==1) break;
		else nn=nn/2;
	}
	cout << "Yes" << endl;
	if(n%2==0) nn=n-2;
	else nn=n-1;
	cout << "1 2" << endl; 
	cout << "2 3" << endl;
	cout << "3 " << 1+n << endl;
	cout << 1+n << " " << 2+n << endl;
	cout << 2+n << " " << 3+n << endl;
	for(i=4;i<=nn;i=i+2){
		cout << "1 " << (i) << endl;
		cout << (i) << " " << (i+1) << endl;
		cout << "1 " << (i+1+n) << endl;
		cout << (i+1+n) << " " << (i+n) << endl;
	}
	if(n%2==0){
		j=1;
		while(1){
			if(n<j){
				j=j/2;
				break;
			}
			j=j*2;
		}
		cout << n << " " << n+j+1 << endl;
		cout << 2*n << " " << n-j << endl;
	}
	return 0;
}