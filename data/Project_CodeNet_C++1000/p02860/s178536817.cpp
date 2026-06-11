#include <string>
#include <iostream>
using namespace std;

int main() {
	int N; string S; bool t = true; cin >> N >> S;
	if (N % 2 == 1) t = false;
	else for (int i = 0; i < (N / 2); i++) {
		if (S[i] != S[(N / 2) + i]) {
			t = false;
			break;
		}
	}
		if (t) cout << "Yes"; 
		else cout << "No";
		cout << endl;
}