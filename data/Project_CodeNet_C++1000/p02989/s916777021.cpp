#include <bits/stdc++.h>
using namespace std;


int main() {
	int N,H,ans;
	cin >> N;
	vector<int> vec(N);
	H = N / 2;
	for (int i = 0; i < N ; i++)
	{
		cin >> vec.at(i);
	}

	sort(vec.begin(), vec.end());
	ans = vec.at(H) - vec.at(H-1);
	cout << ans << endl;
}