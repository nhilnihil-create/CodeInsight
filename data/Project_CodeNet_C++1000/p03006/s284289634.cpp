#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n;
	cin >> n;
	long long x[n],y[n];
	for(long long i=0;i<n;i++){
		cin >> x[i] >> y[i];
	}
	map<pair<long long ,long long>,long long> a;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			a[make_pair(x[i]-x[j],y[i]-y[j])]++;
			a[make_pair(x[j]-x[i],y[j]-y[i])]++;
		}
	}
	long long ans=0;
	for(auto i:a){
		ans=max(ans,i.second);
	}
	cout << n-ans << endl;
	return 0;
}
