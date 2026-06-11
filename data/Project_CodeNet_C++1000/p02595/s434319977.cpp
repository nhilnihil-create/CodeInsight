#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	long long int D,N,ans=0;
	long long int X[1000001], Y[1000001];
	cin >> N >> D;
	for (int i = 0; i < N; i++) {
		cin >> X[i] >> Y[i];
	}
	for (int i = 0; i < N; i++) {
		if (X[i] * X[i] + Y[i] * Y[i] <= D * D)ans++;
	}
	cout << ans << endl;
	return 0;
}