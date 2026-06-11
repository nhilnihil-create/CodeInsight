#pragma GCC optimize ("O3")
#pragma GCC target ("sse4") // wonderful

#include <bits/stdc++.h>
using namespace std;


int main()
{

	int n, k; cin >> n >> k;

	vector<int> arr {};
	arr.push_back(k);

	int k_left = k, k_right = k;

	for (int i = 1; i < n; i++) {
		k_left -= 1;
		k_right += 1;
		arr.push_back(k_left);
		arr.push_back(k_right);
	}

	sort(arr.begin(), arr.end());

	for (int x : arr)
		cout << x << " ";

	
	return 0;

}