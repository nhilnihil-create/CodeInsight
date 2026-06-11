#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

int main(){

	int n, total = 0;
	scanf("%d", &n);
	
	vector<int> v(n);
	rep(i,n){
		scanf("%d ", &v[i]);
		total += v[i];
	}

	int s, min = 1e5;
	
	rep(t,n){
		s = 0;
		rep(i,t){
			s += v[i]; 
		}
		if ( abs(total - 2*s) <= min ) min = abs(total - 2*s);

	}
	
	printf("%d\n", min);
	return 0;
}