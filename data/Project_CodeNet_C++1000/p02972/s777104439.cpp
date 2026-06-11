#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	int n; cin >> n;
	vector<int> A;
	for (int i=0; i<n; i++) {
		int a; cin >> a;
		A.push_back(a);
	}

	vector<int> B(n, 0);
	vector<int> R;
	for (int i=n-1; i>=0; i--) {
		int c = i+1;
		int a = A[i];
		int psum = 0;
		for (int j=2; j*c <= n; j++) {
			psum += B[j*c - 1];
		}
		if ((psum + a)%2==1) {
			B[i] = 1;
			R.push_back(c);
		}
	}
	int m = R.size();
	cout << m << endl;
	if (m==0) return 0;
	for (int i=0; i<m; i++) {
		cout << R[m - i - 1] << " ";
	}
	cout << endl;
	return 0;
}