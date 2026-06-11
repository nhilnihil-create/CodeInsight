#include <bits/stdc++.h>

using namespace std;


#define PI 3.14159265
#define int long long



main(){

	int n, m; cin >> n >> m;

	vector <int> a(m);

	for(int i = 0; i < m; i++){
		cin >> a[i];
	}

	if(accumulate(a.begin(), a.end(), 0LL) > n){
		cout << -1 << endl;
	}else{
		cout << n - accumulate(a.begin(), a.end(), 0LL) << endl;
	}

	
	
	return 0;
}