#include<iostream>
#include<vector>
#include<algorithm>

int main(void){
    long long n, k;
    std::cin >> n >> k;
    std::vector<int> a(n), f(n);
    for(int i = 0; i < n; i++){
	std::cin >> a[i];
    }
    for(int i = 0; i < n; i++){
	std::cin >> f[i];
    }
    std::sort(a.begin(), a.end());
    std::sort(f.rbegin(), f.rend());
    long long l = 0, r = 1e12+1;
    long long mid;
    while(l < r){
	mid = (l + r) / 2;
	long long sum = 0;
	// std::cout << mid << std::endl;
	for(int i = 0; i < n; i++){
	    // std::cout << sum << std::endl;
	    // std::cout << a[i] << std::endl;
	    // std::cout << mid << std::endl;
	    // std::cout << "f[i]:" << f[i] << std::endl;
	    // std::cout << "mid / f[i]:" << mid / f[i] << std::endl;
	    // std::cout << a[i] - mid / f[i] << std::endl;
	    sum += std::max(0ll, a[i] - mid / f[i]);
	}
	// std::cout << mid << std::endl;
	if(sum <= k){
	    r = mid;
	}else{
	    l = mid + 1;
	}
	// std::cout << mid << std::endl;
    }
    std::cout << r << std::endl;


    return 0;
}

