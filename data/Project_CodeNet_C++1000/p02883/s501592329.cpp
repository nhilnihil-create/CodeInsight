#include <bits/stdc++.h>

using namespace std;

int main(){

	long long int n,k,bot=0, mid, top,aux,au,z=0;
	
	cin >> n >> k;
	vector<long long int>a(n);
	vector<long long int>c(n);

	for(int i=0;i<n;i++) cin >> a[i];	
	for(int i=0;i<n;i++) cin >> c[i];	

	sort(a.begin(),a.end());
	sort(c.begin(),c.end());

	top = a[n-1]*c[n-1];

	while(top>bot){
		mid = (bot + top)/2;
		
		aux=0;

		for(int i=0;i<n;i++){
			au = min(mid/c[i], a[n-i-1]);
			aux+= a[n-1-i]-au;
			if(aux>k) break;
		}

		if(aux>k) bot=mid+1;
		else top=mid;

	
	}

		cout << bot << endl;
	return 0;
}