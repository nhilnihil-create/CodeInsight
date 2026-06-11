#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,x;
	int cnt[200010] = {0};
	cin >> n;
	for(int i = 1; i < n; i++) {
		cin >> x;
		cnt[x]++;
	}
	for(int i = 1; i <= n; i++) {
		cout << cnt[i] << endl;
	}
	return 0;
}
