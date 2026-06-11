#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int n, ans = 0;
	scanf("%d", &n);
	vector<int> a(n);
	for(int i=0; i<n; i++) scanf("%d", &a[i]);
	sort(a.begin(), a.end());
	for(int i=0; i+2<n; i++) {
		for(int j=i+1; j+1<n; j++) {
			for(int k=j+1; k<n; k++) {
				if(a[i] != a[j] && a[j] != a[k] && (a[i]+a[j]>a[k])) ans++;
			}
		}
	}
	printf("%d", ans);
	
	return 0;
}
