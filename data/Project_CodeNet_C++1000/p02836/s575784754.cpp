#include <bits/stdc++.h>
using namespace std;


int main() {
	string S;
	cin >> S;
	int n = S.size() - 1;
	int count = 0;
	for(int i = 0; i < n; i++){
		if(S[i] != S[n]){
			count++;
			n -= 1;
		} else {
			n -= 1;
		}
	}
	cout << count << endl;
}
