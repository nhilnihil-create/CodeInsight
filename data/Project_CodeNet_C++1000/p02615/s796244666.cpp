#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <functional>
#define ll long long int
using namespace std;

int main() {
	ll N, x, ans=0;

	cin >> N;
	vector<ll> point(N);

	for (int i = 0; i < N; i++){
		cin >> point[i];
	}
	sort(point.begin(), point.end(), greater<ll>());

	for (int i = 0; i < N; i++){
		if (i == 0){
			ans += 0;
		}
		else if (i == 1){
			ans += point[0];
		}
		else{
			x = i / 2;
			ans += point[x];
		}
	}

	cout << ans << endl;

	return 0;
}