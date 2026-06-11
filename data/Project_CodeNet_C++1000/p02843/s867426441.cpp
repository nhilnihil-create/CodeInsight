#include <bits/stdc++.h>
using namespace std;

int main(){
	int x;
	cin >> x;
	vector<int> d(x+1);
	if (x<100) {cout << '0'; return 0;}
	if (x<106) {cout << '1'; return 0;}
	for(int i = 0; i< 100;i++) d[i]=0;
	d[100] = d[101] = d[102] = d[103] = d[104] = d[105] = 1;
	for (int i = 106; i < x+1; i++){
		d[i] = (d[i-100] || 
				d[i-101] ||
				d[i-102] || 
				d[i-103] || 
				d[i-104] || 
				d[i-105]);
		}
	d[x] ? cout << '1' : cout << '0';  
	
	
 }
