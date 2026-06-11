#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	long long N{}, M{};
	cin >> N >> M;

	priority_queue<int> price;
	for (size_t i = 0;i < N;++i) {
		int temp;
		cin >> temp;
		price.push(temp);
	}

	for (size_t i = 0;i < M;++i) {
		int temp = price.top();
		price.pop();
		price.push(temp / 2);

	}

	long  long total = 0;
	for (size_t i = 0;i < N;++i) {
		total += price.top();
		price.pop();
	}
	cout << total << endl;

}