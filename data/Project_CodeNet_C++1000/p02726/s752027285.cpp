#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;

void swap(int a,int b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int main(void) {
	int n,x,y;
	cin >> n >> x >> y;
	vector<ll>ans(n);

	for (int i = 1; i <= n - 1; i++) {
		for (int j = i+1; j <= n; j++) {
			int saitan = min(j-i,abs(i-x)+abs(j-y)+1);
			ans[saitan]++;
		}
	}

	

	for (int i = 1; i < n;i++) {
		cout << ans[i] << endl;
	}
	return 0;
}