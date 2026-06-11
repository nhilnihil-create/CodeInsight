#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main(){
	IOS;
	int n;
	cin >> n;
	int a[n], b[n];
	for(int i = 0; i < n; i++)
		cin >> a[i] >> b[i];

	sort(a, a+n);
	sort(b, b+n);
	if( n&1 ){
		int md = n/2;
		cout << b[md] - a[md]+1 << endl;
	}else{
		int m1 = n/2-1, m2 = n/2;
		cout << (b[m1]+b[m2])-(a[m1]+a[m2]) + 1 << endl;
	}
	return 0;
}