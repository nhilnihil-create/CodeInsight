#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> w(n);
	int sum = 0;
	for(int i = 0; i < n; i++){
		cin >> w[i];
		sum += w[i];
	}
	int mini =  sum;
	int prefix_sum = 0;
	for(int i = 0; i < n; i++){
		cin >> w[i];
		prefix_sum += w[i];
		mini = min(mini,abs(prefix_sum - (sum - prefix_sum)));
	}
	cout << mini << endl;
	return 0;
}

