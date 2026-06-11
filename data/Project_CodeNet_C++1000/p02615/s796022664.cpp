#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; ++i) cin >> a[i];
	sort(a.begin(),a.end(),greater<int>());
	long long ans=a[0];
	for(int i=2; i<n; ++i){
		ans += a[i/2];
	}
	cout << ans << endl;
}
