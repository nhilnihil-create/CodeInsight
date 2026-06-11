#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	long long int sum = 1000;
	cin >> n;
	vector<int> num(n);
	for (int i = 0; i < n; i++)
		cin >> num[i];
	for (int i = 0; i < n - 1; i++)
		if (num[i] < num[i + 1])
			sum = (sum / num[i]) * num[i + 1] + (sum - num[i] * (sum / num[i]));
	cout << sum << '\n';
	return 0;
}
