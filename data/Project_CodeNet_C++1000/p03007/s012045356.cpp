#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<math.h>

#define DIV 1000000007
using namespace std;
using ll = long long;

int main(void) {
	int N;
	cin >> N;

	vector<ll> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	
	sort(A.begin(), A.end());
	ll ans = 0;
	int mns = 0;
	for (int i = 0; i < N; i++) {
		if ((i == 0 || A[i] < 0) && i < N - 1) {
			mns++;
			ans -= A[i];
		}
		else
		ans += A[i];
	}
	cout << ans << endl;

	ll temp1 = A[N - 1];
	for (int i = 1; i < mns; i++) {
		cout << temp1 << " " << A[i] << endl;
		temp1 -= A[i];
	}

	ll temp2 = A[0];
	for (int i = mns; i < N - 1; i++) {
		cout << temp2 << " " << A[i] << endl;
		temp2 -= A[i];
	}

	cout << temp1 << " " << temp2 << endl;
}
