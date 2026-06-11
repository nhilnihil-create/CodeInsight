#include <bits/stdc++.h>

using namespace std;
using i64 = long long int;
using ui64 = unsigned long long int;

//////

int main(){
	vector<int> a(300000,1);
	a[0] = a[1] = 0;
	for(int i=2;i<300000;i++){
		if(!a[i])continue;
		for(int j=2;i*j<300000;j++){
			a[i*j] = 0;
		}
	}
	for(int i=0;i<299999;i++){
		a[i+1] += a[i];
	}
	int n;
	while(cin >> n,n){
		cout << a[2*n] - a[n] << endl;
	}
}

