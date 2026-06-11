#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,s=0,i,j;
	int x[100];
	int min = INT_MAX;
	cin >> n;
	for(i=0;i<n;i++){
		cin >> x[i]; 
	}
	for (i=1;i<=100;i++){
		s = 0;
		for(j=0;j<n;j++){
			s += (x[j]-i)* (x[j]-i); 
		}
		if (s < min) min = s;
	}
	cout << min;
	return 0;
}
