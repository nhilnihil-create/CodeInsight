#include <iostream>
#include <algorithm>

int main()
{
	int N;
	std::cin >> N;
	std::pair<int,int>* A = new std::pair<int,int>[N+1];
	for (int i=1; i<=N; i++) {
		std::cin >> A[i].first;
		A[i].second = i;
	}
	std::sort(A+1, A+N+1);
	for (int i=1; i<=N; i++) std::cout << A[i].second << " ";
	std::cout << std::endl;
	delete[] A;
	return 0;
}
