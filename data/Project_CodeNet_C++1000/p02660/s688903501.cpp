#include <iostream>


int main(void){
	long N, n;
	int res = 0;
	std::cin >> N;

	if(N == 1) std::cout << 0 << std::endl;
	else {
		n = N;
		int cnt, exp;
		for(long i = 2; i * i <= N; i++){
			cnt = 0;
			exp = 1;
			while(n % i == 0){
				n /= i;
				cnt++;
			}
			while(cnt - exp >= 0){
				cnt -= exp;
				res++;
				exp++;
			}
		}
		if(n != 1) res++;
		std::cout << res << std::endl;
	}
	return 0;
}
