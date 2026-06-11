#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define F first
#define S second

signed main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int v = (n*(n+1)*(n+2))/6;
	int e=0;
	int a,b;
	for(int i=0; i<n-1; i++){
		cin >> a >> b;
		if(a>b)
			swap(a,b);
		e += a*(n-b+1);
	}
	cout << v-e;


	
	

	return 0;
}