#include<iostream>
#include<algorithm>
#include <stdio.h>
#include <string>
using namespace std;

int main() {
	int N;
	string S;
	cin >> N >> S;
	int ans = 0;


	for (int i = 0; i < 1000; i++) {
		string s_;
		if (i >= 100) {
			s_ = to_string(i);
		}
		else if(i >= 10){
			s_ = "0" + to_string(i);
		}
		else if(i >= 0){
			s_ = "00" + to_string(i);

		}
		else {
			s_ = "000";
		}
		
		int n1 = 1000, n2 =1000, n3 =1000;
		for (int j = 0; j < N; j++) {
			if (S[j] == s_[0]) {
				n1 = j;
				break;
			}
		}
		for (int j = n1 +1; j < N; j++) {
			if (S[j] == s_[1]) {
				n2 = j;
				break;
			}
		}
		for (int j = n2+1; j < N; j++) {
			if (S[j] == s_[2]) {
				n3 = j;
				break;
			}
		}
		if (n1 != 1000 && n2 != 1000 && n3 != 1000) {
			ans++;
		}
	}


	cout << ans << endl;
	return 0;


}