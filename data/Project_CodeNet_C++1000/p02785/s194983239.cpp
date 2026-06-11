#include <bits/stdc++.h>

using namespace std;


int main()
{
	int N, K;
	cin >> N >> K;
	vector<int> v(N);
	for (int i = 0 ; i < N; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());
	long long int s = 0;
	for (int i = K; i < v.size(); ++i)
		s += v[v.size() - i - 1];
	cout << s;


	return 0;
}
