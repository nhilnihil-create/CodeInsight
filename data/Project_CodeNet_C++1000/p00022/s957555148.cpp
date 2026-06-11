
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
#include <cctype>
#include <complex>
#include <vector>
#include <algorithm>

using namespace std;


bool solve(){

	while(1){
		int n;
		cin>> n;
		if(!n) break;
		
		vector<int> a(n,0);
		for(int i=0;i<n;i++){
			cin>> a[i];
		}
		
		int sum = -100000;
		for(int i=0;i<n;i++){
			int sum2 = a[i];
			if(sum < sum2) sum = sum2;
			for(int j=i+1;j<n;j++){
				sum2 += a[j];
				if(sum < sum2) sum = sum2;
			}
		}
		
		cout<< sum<< endl;
	}
	return true;
}

int main(){
	cout.setf(ios::fixed);
	cout.precision(10);
	solve();

	return 0;
}

 