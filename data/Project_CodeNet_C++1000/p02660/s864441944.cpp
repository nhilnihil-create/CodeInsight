#include<iostream>
#include<vector>
using namespace std;

int main() {
	long int n;
	cin >> n;

	vector<pair<long int, int>> fs;
	for (long int i = 2;i * i <= n;i++) {
		int x = 0;
		while (n % i == 0) {
			n /= i;
			x++;
		}
		fs.emplace_back(i, x);
	}
	if (n > 1) fs.emplace_back(n, 1);

	int num;
	num = fs.size();
	int ans = 0;
	for (int i = 0;i < num;i++) {
		int y = fs[i].second;
		int j = 1;
		while(y>0) {
			y -= j;
			j++;
			if(y>=0) ans++;
		}
	}

	cout << ans;
	return 0;
}