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
#include <cassert>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int main() {
	int K,N;
	scanf("%d%d", &K,&N);
	vector<int> A(N);
	rep(i, N)scanf("%d", &A[i]);
	sort(A.begin(), A.end());
	int maxa = A[N - 1] - A[0];
	maxa = min(maxa, K - maxa);
	rep(i, N-1)maxa = max(maxa, A[i + 1] - A[i]);
	printf("%d", K - maxa);
}