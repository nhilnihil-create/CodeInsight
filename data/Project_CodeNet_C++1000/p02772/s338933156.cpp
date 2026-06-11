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

	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;

		//偶数
		if (A % 2 == 0) {
			if (A % 3 == 0 || A % 5 == 0) {
				//3または5で割り切れる
			}
			else {
				//上記以外
				cout << "DENIED" << endl;
				return 0;
			}
		}
	}

	cout << "APPROVED" << endl;

}
