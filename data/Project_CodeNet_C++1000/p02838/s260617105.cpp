#include<iostream>
#include<vector>

const static int MOD = 1e9 + 7;

int main(void){
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    for(int i = 0; i < n; i++){
	std::cin >> a[i];
    }
    long long x;
    long long ans = 0;
    long long tmp;
    for(long long i = 0; i < 60; i++){
	x = 0;
	for(int j = 0; j < n; j++){
	    long long cur = a[j];
	    if((a[j] >> i) & 1) x++;
	}
	tmp = x * (n - x) % MOD;
	for(int j = 0; j < i; j++){
	    tmp = (tmp * 2) % MOD;
	}
	// std::cout << tmp << std::endl;
	ans = (ans + tmp) % MOD;
    }
    std::cout << ans << std::endl;
    return 0;
}

