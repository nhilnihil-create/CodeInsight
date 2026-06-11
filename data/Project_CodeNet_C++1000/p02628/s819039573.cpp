#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	vector<int> P;
	for (int i = 0; i < N; i++) {
		int p;
		cin >> p;
		P.push_back(p);
	}

	sort(P.begin(), P.end());

	int total = 0;
	for (int i = 0; i < K; i++) {
		total += P[i];
	}
	cout << total << endl;
}
