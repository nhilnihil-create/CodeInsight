#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	int p[100000];
	int c = 0;
	for(int i = 2; i < 300000; i++){
		int f = 0;
		for(int j = 2; j <= sqrt(i); j++){
			if(i%j ==0) f= 1;
		}
		if(f == 0){
			p[c] = i;
			c++;
		}
	}
	cin>>n;
	while(n!=0){
		int ans = 0;
		int m=0,M=0;
		for(int i = 0; i < c; i++){
			 if(m == 0&&p[i] > n)m = i;
			 else if(M == 0&&p[i] > 2*n)M = i -  1;
		}
		cout << M-m+1 << endl;
		cin >> n;
	}
	return 0;
}
