#include <bits/stdc++.h>
using ll = long long;

signed main(){
	int N, K, S;
	std::cin >> N >> K >> S;
	std::vector<int> ans(N, 1e9);
	for(int i = 0; i < K; i++) ans[i] = S;
	if(S == 1e9){
		for(int i = K; i < N; i++) ans[i] = 1;
	}
	for(auto i : ans) std::cout << i << std::endl;
}