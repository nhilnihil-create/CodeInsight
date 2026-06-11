#pragma warning(disable:4996)
#include<iostream>
#include<stdio.h>
#include<sstream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<limits.h>
using namespace std;
using ll = long long int;
inline ll get(ll i) {
	return (i + 1) * i / 2;
}
int main() {
	ll N;
	cin >> N;
	ll NDT = get(N / 3) * 3, NDF = get(N / 5) * 5, NDFIT = get(N / 15) * 15,
		FN = get(N);
	cout << FN - NDT - NDF + NDFIT;
	return 0;
}