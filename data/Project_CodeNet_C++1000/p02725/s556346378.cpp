#include <iostream>
#include <algorithm>

int main()
{
	int K, N;
	std::cin >> K >> N;
	int* A = new int[N];
	for (int i=0; i<N; i++) std::cin >> A[i];
	int* d = new int[N];
	for (int i=0; i<N-1; i++) d[i] = A[i+1] - A[i];
	d[N-1] = A[0] + K - A[N-1];
	std::sort(d, d+N);
	int res = 0;
	for (int i=0; i<N-1; i++) res += d[i];
	std::cout << res << std::endl;
	return 0;
}
