#include <iostream>
#include <vector>
typedef long long int ll;


int main(void){
	int N;
	ll money = 1000, stock = 0, dif = 0;
	std::cin >> N;
	std::vector<int> A(N, 0);
	for(int i = 0; i < N; i++) std::cin >> A[i];
	for(int i = 1; i < N; i++){
		// std::cout << i << " " << dif[i+1] << " " << money << endl;
		dif = A[i] - A[i-1];
		if(dif > 0){
		 	stock = money / A[i-1];     
			money += stock * dif;
			stock = 0;
		}
	}
	// std::cout << money << " " << stock << endl;
	std::cout << money << std::endl;
	return 0;
}
