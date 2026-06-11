#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	string S, M;
	cin >> S >> M;
	int N = 0;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == M[i]) {
			N + 0;
		}
		else {
			N++;
		}
	}
	cout << N << endl;
}