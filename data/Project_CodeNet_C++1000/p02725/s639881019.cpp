#include <bits/stdc++.h>

using namespace std;

//typedef pair<int,int> P;
typedef long long ll; 

#define int ll


main(){
	int num[100]={0};

	int k,n;
	cin >> k >> n;
	
	int a[2*n];
	for(int i=0;i<n;i++) cin >> a[i];
	
	for(int i=0;i<n;i++) a[i+n] = a[i]+k;

	int ans = 1e9;
	for(int i=0;i<n;i++){
		ans = min(ans,a[i+n-1]-a[i]);
	}

	cout << ans << endl;

	return 0;
}