#include<iostream>
#include<cmath>
using namespace std;
int lst[110];
int n;
inline long long value(int pos) {
	long long temp=0;
	for (int i = 0; i < n; i++) {
		temp += (lst[i] - pos) * (lst[i] - pos);
	}
	return temp;
}
int main() {
	int minm = 110, maxm=0;
	long long ans = INT64_MAX;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> lst[i];
		if (lst[i] < minm)minm = lst[i];
		if (lst[i] > maxm)maxm = lst[i];
	}
	for (int i = minm; i <= maxm; i++) {
		if (value(i) < ans)ans = value(i);
	}
	cout << ans << endl;
	return 0;
}