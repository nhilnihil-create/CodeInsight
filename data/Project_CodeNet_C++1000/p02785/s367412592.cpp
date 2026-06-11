#include<iostream>
#include<algorithm>
#include<vector>

int main(void){
    int n, k;
    std::cin >> n >> k;
    if(n <= k){
	std::cout << 0 << std::endl;
	return 0;
    }
    std::vector<int> h(n);
    for(int i = 0; i < n; i++){
	std::cin >> h[i];
    }
    std::sort(h.rbegin(), h.rend());

    long long ans = 0;
    for(int i = k; i < n; i++){
	ans += h[i];	
    }
    std::cout << ans << std::endl;
    return 0;
}

