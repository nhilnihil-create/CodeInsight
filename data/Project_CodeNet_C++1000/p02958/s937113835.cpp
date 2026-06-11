#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> P;
	for (int i = 0; i < N; i++) {
		int p;
		cin >> p;
		P.push_back(p);
	}

	vector<int> P_rev = P;
	sort(P_rev.begin(), P_rev.end());

	int count = 0;
	for (int i = 0; i < N; i++) {
		if (P[i] != P_rev[i]) {
			count++;
		}
	}
	if (count == 2 || count==0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

}



