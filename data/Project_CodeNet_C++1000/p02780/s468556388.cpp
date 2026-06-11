#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>

int main(void){
    int n, k;
    std::cin >> n >> k;
    std::vector<int> p(n);

    for(int i = 0; i < n; i++){
	std::cin >> p[i];
    }
    // std::sort(p.rbegin(), p.rend());

    double tmp = 0.0;
    for(int i = 0; i < k; i++){
        tmp += (p[i] + 1.0) / 2.0;
    }

    double ans = tmp;
    for(int i = 1; i <= n - k; i++){
    	tmp = tmp - p[i - 1] / 2.0 + p[i + k - 1] / 2.0;
	ans = std::max(ans, tmp);
    }
    std::cout << std::fixed << std::setprecision(15) << ans << std::endl;
    return 0;
}

