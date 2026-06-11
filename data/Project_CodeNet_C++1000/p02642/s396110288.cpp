#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <vector>


int main(void){
	int N, res = 0;
	std::vector<bool> dp(1000001, false);
	std::cin >> N;
	std::vector<int> A(N, 0);
	for(int i = 0; i < N; i++){
		std::cin >> A[i];
		dp[A[i]] = true;
	}
	std::sort(A.begin(), A.end());
	
	for(int i = 0; i < N; i++){
		if(!dp[A[i]]) continue;
		else if((i < N-1 && A[i] == A[i+1]))
			dp[A[i]] = false;
		for(int j = 2*A[i]; j <= A[N-1]; j += A[i]){
			dp[j] = false;
		}
		
		if(dp[A[i]]) res++;
	}
	std::cout << res << std::endl;
	return 0;
}

