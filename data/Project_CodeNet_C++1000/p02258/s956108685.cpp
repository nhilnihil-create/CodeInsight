#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
	int n;
	cin >> n;
	vector<int> r(n);

	int buy;
	int profit;
	for (int i = 0; i < n; i++){
		cin >> r[i];
		if (i == 1){
			profit = r[1] - r[0];
		}
		else if (i > 1){
			profit = max(profit, r[i] - buy);
		}
		if (i == 0){
			buy = r[i];
		}
		else if (buy > r[i]){
			buy = r[i];
		}
	}

	cout << profit << endl;
	return 0;
}