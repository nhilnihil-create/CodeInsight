#include<iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int a[n]; int b[n]; int c[n-1];
	for(int i=0; i<n; i++) cin >> a[i];
	for(int i=0; i<n; i++) cin >> b[i];
	for(int i=0; i<n-1; i++) cin >> c[i];
		
	int ans = b[a[0]-1];

	for(int i=1; i<n; i++){
		ans += b[a[i]-1];
		if(a[i]==a[i-1]+1){
			ans += c[a[i]-2];
		}
	}
	cout << ans;
	return 0;
}