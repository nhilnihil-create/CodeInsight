#include<bits/stdc++.h>
using namespace std;

string S;

bool check(string s) {
	long long n = s.size();
	for(long long i = 0; i < n; i++) {
		if(s[i] != s[n-1-i]) {
			return false;
		}
	}
	return true;
}

int main(){
	cin >> S;
	long long N = S.size();

	if(!check(S)) {
		cout << "No" << endl;
		return 0;
	}

	if(!check(S.substr(0, (N-1)/2))) {
		cout << "No" << endl;
		return 0;
	}

	if(!check(S.substr((N+3)/2-1, N))) {
		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << endl;
}
