#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, m, k, ans = 0;
	cin >> n >> m >> k;
	long long A[n+1], B[m+1];
	A[0] = 0, B[0] = 0;
	cin >> A[1];
	for(int i=2; i<=n; ++i){
		cin >> A[i];
		A[i] = A[i-1] + A[i];
	}
	cin >> B[1];
	for(int i=2; i<=m; ++i){
		cin >> B[i];
		B[i] = B[i-1] + B[i];
	}
	for(int i=0; i<=n; ++i){
		int L = 0, R = m;
		while(L<=R){
			int mid=L+(R-L)/2;
			if(B[mid]+A[i]<=k){
				if(B[mid+1]+A[i]>k||mid==m){
					ans = max(ans, i+mid);
				}
				L=mid+1;
			}
			else{
				R=mid-1;
			}
		}
	}
	cout << ans;
}
