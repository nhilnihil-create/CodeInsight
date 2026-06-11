#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	int K;
	cin >> K;

	string S;
	cin >> S;

	if (S.length() <= K) {
		cout << S << endl;
	}
	else {
		for (int i = 0; i < K; i++) {
			cout << S[i];
		}
		cout << "..." << endl;
	}

	
}
