#include <bits/stdc++.h>

#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
using namespace std;

int main(){
	int k, n;	cin >> k >> n;
	int a[n];
	for( int i = 0; i < n; i++ ){
		cin >> a[i];
	}
	int distance[n];
	int ans = 0;

	for( int i = 0; i < n - 1; i++ ){
		distance[i] = a[i+1] - a[i];
	}
	distance[n - 1] = k - a[n - 1] + a[0];

	sort( distance, distance + n );

	for( int i = 0; i < n - 1; i++ ){
		ans += distance[i];
	}

	cout << ans << endl;

	return 0;
}
