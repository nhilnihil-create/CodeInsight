#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <iomanip>
#define intt long long

bool check(std::pair<intt, intt> a, std::pair<intt, intt> b) {
	return a.second < b.second;
}

int main(){
	intt N;  std::cin >> N;
	std::vector<std::pair<intt, intt>> A(N);
	for (int i = 0; i < N; ++i)
		std::cin >> A[i].first >> A[i].second;
	std::sort(A.begin(), A.end(), check);
	bool flag = true;
	intt sum{ 0 };
	for (int i = 0; i < N; ++i) {
		sum += A[i].first;
		if (sum > A[i].second)
			flag = false;
	}
	std::cout << (flag ? "Yes" : "No") << std::endl;
}