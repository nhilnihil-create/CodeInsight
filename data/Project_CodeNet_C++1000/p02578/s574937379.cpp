#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<functional>
#include <random>
#include<iostream>
#include<iomanip>
using namespace std;
int N;
long long A[200000];
long long max_height;
long long ans;


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	max_height = 0;
	ans = 0;
	for (int i = 0; i < N; i++) {
		if (max_height < A[i]) {
			max_height = A[i];
		}
		else {
			ans += max_height - A[i];
		}
	}
	cout << ans;
}