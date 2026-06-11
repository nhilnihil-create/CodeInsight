#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int mxN=2e5;
int n, a[mxN];
ll c[mxN], ans;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> a[i], --a[i];
		++c[a[i]];
	}
	for(int i=0; i<n; ++i)
		ans+=c[i]*(c[i]-1)/2;
	for(int i=0; i<n; ++i) {
		ans-=c[a[i]]*(c[a[i]]-1)/2;
		--c[a[i]]*(c[a[i]]-1)/2;
		ans+=c[a[i]]*(c[a[i]]-1)/2;
		cout << ans << "\n";
		ans-=c[a[i]]*(c[a[i]]-1)/2;
		++c[a[i]]*(c[a[i]]-1)/2;
		ans+=c[a[i]]*(c[a[i]]-1)/2;
	}
}