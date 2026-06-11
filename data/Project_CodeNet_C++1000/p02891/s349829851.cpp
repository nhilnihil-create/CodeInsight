#include<iostream>
#include<string>
using namespace std;
int main() {
	string S;
	long long int spart[100];

	long long int k;
	int diflag = 0;
	cin >> S;
	cin >> k;

	int i;
	int j = 0;
	for (i = 0; i < 100; i++) {
		spart[i] = 0;
	}
	spart[0] = 1;
	for (i = 0; i < S.length() - 1; i++) {
		if (S[i] == S[i + 1]) {
			spart[j]++;
		}
		else {
			diflag = 1;
			j++;
			spart[j]++;
		}
	}
	long long int counter = 0;
	if (diflag == 1) {
		if (S[0] == S[S.length() - 1]){
			if ((spart[0] % 2 == 1) && (spart[j] % 2 == 1))counter = -1;
			spart[0] = spart[0] + spart[j];
			
			//spart[j] = 0;
			j = j - 1;
		}
		for (i = 0; i <= j; i++) {
			//cout << spart[i] ;
			counter = counter + k * ((spart[i] - (spart[i] % 2)) / 2);
		}
		cout << counter;
	}
	else {
		if (k % 2 == 0) {
			cout << S.length() * k / 2;
		}
		else if (S.length() % 2 == 0) {
			cout << S.length() * k / 2;

		}
		else {
			cout << (S.length() * k - 1) / 2;
		}
	}

	return 0;
}
