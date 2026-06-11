#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string S, T;
	cin >> S;
	cin >> T;

	int n = S.size() - T.size() + 1;
	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		a[i] = 0;
		for (int j = 0; j < T.size(); j++) {
			if (S[j + i] != T[j]) {
				a[i]++;
			}
		}
	}

	int min = a[0];
	for (int i = 1; i < n; i++) {
		if (min > a[i]) {
			min = a[i];
		}
	}

	cout << min << endl;	
}