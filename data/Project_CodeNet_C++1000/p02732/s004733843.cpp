#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <map>
#include <vector>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	vector<int> A(n);
	map <int, long long> mp;
	for (int i = 0; i < n; i++) {
		scanf("%d",&A[i]);
		mp[A[i]]++;
	}
	long long v=0;
	for (auto a : mp) {
		a.second = a.second * (a.second - 1) / 2;
		v += a.second;
	}
	for (int i = 0; i < n; i++) {
		printf("%lld\n", v-mp[A[i]]+1);
	}
}
