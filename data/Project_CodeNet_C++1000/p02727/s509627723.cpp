#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<cstdlib>
#include<set>
#include<algorithm>
#include<functional>
using namespace std;
long long x, y, a, b, c, qx[100005], qy[100005], qz[100005], t[200005];
inline void readAndSort(long long* arr, long long num) {
	for (int i = 0; i < num; i++) {
		scanf("%lld", arr + i);
	}
	sort(arr, arr + num, greater<long long>());
}
int main() {
	scanf("%lld%lld%lld%lld%lld", &x, &y, &a, &b, &c);
	readAndSort(qx, a);
	readAndSort(qy, b);
	readAndSort(qz, c);
	int j, px, py;
	j = px = py = 0;
	while (px < x && py < y) {
		if (qx[px] > qy[py]) {
			t[j] = qx[px];
			px++;
		}
		else {
			t[j] = qy[py];
			py++;
		}
		j++;
	}
	while (px < x) {
		t[j] = qx[px];
		j++;
		px++;
	}
	while (py < y) {
		t[j] = qy[py];
		j++;
		py++;
	}
	for (int i = 0; i < c; i++) {
		if (qz[i] > t[j - i - 1]) {
			t[j - i - 1] = qz[i];
		}
		else {
			break;
		}
	}
	long long sum = 0;
	for (int i = 0; i < j; i++) {
		sum += t[i];
	}
	printf("%lld\n", sum);
	return 0;
}