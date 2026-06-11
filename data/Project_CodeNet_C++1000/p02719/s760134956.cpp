#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <cmath>
#include <iomanip>
#include <functional>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int main() {
	long long N, K;
	scanf("%ld%ld", &N, &K);
	N = N % K;
	N = min(N, abs(N - K));
	printf("%ld", N);
}