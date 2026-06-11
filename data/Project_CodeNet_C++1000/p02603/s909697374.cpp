#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N; cin >> N;
	vector<int>price(N);
	vector<int>valley;
	long long int money=1000,stock=0;
	int num = 0;
	for (int i = 0; i < N; i++)cin >> price[i];

	for (int i = 0; i < N - 1; i++) {
		num++;
		if (num == N)break;
		if (price[i] == price[i + 1])price.erase(price.begin() + i),i--;
	}

	int temp = 0;
	bool down = true;

	while (true) {
		while (down) {
			if (temp >= price.size()-1)break;
			if (price[temp] > price[temp + 1]) { 
				temp++; 
			}
			else {
				down = false;
				break;
			}
		}
		stock = money/price[temp];
		money -= stock * price[temp];
		while (!down) {
			if (temp >= price.size()-1)break;
			if (price[temp] < price[temp + 1]) {
				temp++;
			}
			else {
				down = true;
				break;
			}

		}
		money += stock * price[temp];
		stock = 0;
		if (temp >= price.size()-1)break;
	}
	cout << money << endl;
}