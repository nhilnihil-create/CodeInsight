#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define rep(i,n) for((i)=0;(i)<(int)(n);(i)++)

void swap(int a, int b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int main(void) {
	int A,B,m;
	cin >> A >> B >> m;

	vector<int>a(A);
	vector<int>b(B);
	int ans = 1000000;

	for (int i = 0; i < A; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < B; i++) {
		cin >> b[i];
	}
	
	vector<int>x(m);
	vector<int>y(m);
	vector<int>c(m);

	for (int i = 0; i < m; i++) {
		cin >> x[i]>>y[i]>>c[i];
	}

	for (int i = 0; i < m; i++) {
		ans = min(ans,a[x[i]-1]+b[y[i]-1]-c[i]);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	ans = min(ans, a[0]+b[0]);

	cout << ans << endl;

	return 0;
}