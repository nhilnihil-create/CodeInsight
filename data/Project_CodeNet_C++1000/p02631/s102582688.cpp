#include<iostream>
#include<vector>

int main(void){
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; i++){
	std::cin >> a[i];
    }

    int all = 0;
    for(int i = 0; i < n; i++){
	all ^= a[i];
    }

    for(int i = 0; i < n; i++){
	int ans = all ^ a[i];
	std::cout << ans << std::endl;
    }

    return 0;
}

