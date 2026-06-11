#include<bits/stdc++.h>

using namespace std;

int A, B, M, a[100000], b[100000], x[100000], y[100000], c[100000];
int ans = INT_MAX;
int mia = INT_MAX, mib = INT_MAX;

int main(){
	cin >> A >> B >> M;
	for(int i = 0; i < A; ++i){
		cin >> a[i];
		mia = min(mia, a[i]);
	}
	for(int i = 0; i < B; ++i){
		cin >> b[i];
		mib = min(mib, b[i]);
	}
	ans = min(ans, mia+mib);
	for(int i = 0; i < M; ++i) cin >> x[i] >> y[i] >> c[i];
	for(int i = 0; i < M; ++i){
		ans = min(ans, a[x[i]-1]+b[y[i]-1]-c[i]);
	}
	cout << ans << endl;
}