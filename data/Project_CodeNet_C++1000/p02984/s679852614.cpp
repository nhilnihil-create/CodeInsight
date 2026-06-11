#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
using namespace std;
const int mod = 1000000007;
#define ll long long

int A[100010];
int ans[100010];
int main()
{
	int N;
	cin >> N;
	ll sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		sum += A[i];
	}
	A[N] = 0;
	ll s = 0;
	for (int i = 1; i < N; i += 2) s += A[i];
	ans[0] = sum - s * 2;
	for (int i = 0; i < N; i++) {
		ans[i + 1] = 2 * A[i] - ans[i];
	}
	for (int i = 0; i < N; i++) {
		cout << ans[i] << " " << endl;
	}
	cout << endl;
}
