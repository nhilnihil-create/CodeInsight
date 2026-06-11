#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vint;

int a[200010];
int ans[200010];
int main(){
	int n; cin >> n;
	for(int i=2;i<=n;i++) {
		cin >> a[i];
		ans[a[i]]++;
	}
	for(int i=1;i<=n;i++) cout << ans[i] << endl;
}