#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> L;
	for (int i = 0; i < N; i++) {
		int l;
		cin >> l;
		L.push_back(l);
	}

	sort(L.begin(), L.end());

	int count = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < i; ++j) {
			for (int k = 0; k < j; ++k) {
				if (L[i] != L[j] && L[j] != L[k] && L[k] + L[j] > L[i]) {
					count++;
				}
			}
		}
	}
	cout << count << endl;
}
