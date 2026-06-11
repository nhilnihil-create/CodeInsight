#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	int K;
	scanf("%d", &K);
	string S;
	cin >> S;
	if (S.length() <= K) {
		cout << S << "\n";
	} else {
		cout << S.substr(0, K) << "..." << "\n";
	}

	return 0;
}
