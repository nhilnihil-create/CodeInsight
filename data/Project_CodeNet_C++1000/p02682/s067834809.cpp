#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
#include<queue>

int main() {
	int A, B, C, K;
	std::cin >> A >> B >> C >> K;

	int answer;

	if (A >= K)	answer = K;
	else if (A + B >= K) answer = A;
	else answer = A - (K - A - B);

	std::cout << answer << std::endl;
	return 0;
}