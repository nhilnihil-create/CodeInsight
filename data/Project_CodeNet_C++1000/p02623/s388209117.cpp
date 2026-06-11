#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;

int main() {
	ll n, m, k;
	cin >> n >> m >> k;
	vector<ll> A(1,0);
	vector<ll> B(1,0);

	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		A.emplace_back(k);
	}
	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		B.emplace_back(k);
	}
	ll time = 0;
	ll A_num = 0;
	ll B_num = 0;
	ll max = 0;
	for (int i = 1; i <= n; i++) {
		if (time + A[i] > k) break;
		else {
			time += A[i];
			A_num++;
		}
	}
	for (int i = 1; i <= m; i++) {
		if (time + B[i] > k) break;
		else {
			time += B[i];
			B_num++;
		}
	}
	
	max = A_num + B_num;
	while (B_num < m&&A_num > 0) {
		time -= A[A_num];
		A_num--;
		
		while (time+B[B_num+1]<=k&&B_num<m) {
			B_num++;
			time += B[B_num];
		}
		if (max < A_num + B_num) max = A_num + B_num;
		
	}

	cout << max;
	return 0;
	
}
