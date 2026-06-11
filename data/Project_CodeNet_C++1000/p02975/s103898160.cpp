#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	int N;
	cin >> N;
	unordered_map<int, int>A;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		A[a]++;
	}
	if (A.size() == 1 && A[0] > 0) {
		cout << "Yes" << endl;
		return 0;
	}
	if (A.size() == 2) {
		int Zero=0, Other=0;
		for (const auto& a : A) (a.first == 0 ?  Zero : Other) = a.second;
		cout << (Other == Zero * 2 ? "Yes" : "No") << endl;
		return 0;
	}
	if (A.size() == 3) {
		int Val [3] , Num[3];
		int i = 0;
		for (const auto& a : A) {
			Val[i] = a.first;
			Num[i] = a.second;
			i++;
		}
		if ((Val[0] ^ Val[1]) == Val[2] && Num[0] == Num[1] && Num[1] == Num[2]) cout << "Yes" << endl;
		else cout << "No" << endl;
		return 0;
	}
	if (A.size() >= 4) {
		cout << "No" << endl;
		return 0;
	}
}
