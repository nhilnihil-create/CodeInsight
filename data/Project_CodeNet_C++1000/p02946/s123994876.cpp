#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
		
	for(int i = n-1; i >= 1 ;--i) 
		cout << k-i << ' ';

	cout << k << ' ';

	for(int i = 1; i < n ;++i)
		cout << k+i << ' ';
	
}
