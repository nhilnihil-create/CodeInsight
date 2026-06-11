#include<iostream>
#include<vector>

int main(void){
    int n, k, d;
    std::cin >> n >> k;
    std::vector<int> snuflag(n);
    for(int i = 0; i < k; i++){
	std::cin >> d;
	int a;
	for(int j = 0; j < d; j++){
	    std::cin >> a;
	    a--;
	    if(snuflag[a] == 0) snuflag[a] = 1;
	}
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
	if(snuflag[i] == 0){
	    ans++;
	}
    }
    std::cout << ans << std::endl;

    return 0;
}
