#include <iostream>
#include <vector>

int main(){
	int n;
	std::cin >> n;

	std::vector<int> a(n);
	long long road[n-1][21] = {};

	for(int i = 0; i < n; ++i){
		std::cin >> a[i];
	}

	road[0][a[0]] = 1;

	for(int i = 0; i < n-2; ++i){
		for(int j = 0; j < 21; ++j){
			if(j + a[i+1] <= 20){
				road[i+1][j + a[i+1]] += road[i][j];
			}
			if(j - a[i+1] >= 0){
				road[i+1][j - a[i+1]] += road[i][j];
			}
		}
	}
	std::cout << road[n-2][a[n-1]] << std::endl;

	return 0;
}
