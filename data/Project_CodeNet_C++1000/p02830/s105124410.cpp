#include <iostream>
#include <vector>
#include <string>
using namespace  std;

int main() {
	int N;
	string S, T;
	string ST="";
	cin >> N;
	cin >> S>>T;
	for (int i = 0; i < N; i++) {
		ST = ST + S[i] + T[i];
	}
	cout << ST << endl;
	return 0;
}