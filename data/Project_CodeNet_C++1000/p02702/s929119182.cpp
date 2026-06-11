#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define N 2019

int main(void){
	std::string num;
	int ns = 0, x = 1, t = 0, ans = 0;
	std::cin >> num;
	ns = num.size();
	std::vector<int> cnt(N);

	reverse(num.begin(), num.end());
	for(int i = 0; i < ns; i++){
		cnt[t]++;
		t += x * (num[i] - '0');
		t %= N;
		ans += cnt[t];
		x = x * 10 % N;
		// std::cout << ans;
		// if(i == ns-1) cnt[t]++;
	}
	std::cout << ans << std::endl;
	/*for(int i = 0; i < N; i++)
		if(cnt[i] > 0)       
			std::cout << i << " " << cnt[i] << std::endl;
	*/
	return 0;
}
