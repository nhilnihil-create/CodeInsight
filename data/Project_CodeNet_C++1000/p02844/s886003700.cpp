#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include<vector>
using namespace std;


int main() {
	int n;
	string s;
	cin >> n >> s;
	vector<int> vec(n);
	bool boo[10][10] = { 0 };
	bool b[10] = { 0 };
	int count = 0;
	for (int i = n - 1; i >= 0; i--) {
		vec[i] = count; 
		if (b[s[i] - '0'] == 0) {
			count++;
			b[s[i] - '0'] = 1;
		}
	}
	int ans = 0;
	for (int i = 0; i < n-2; i++) {
		for (int j = i + 1; j < n-1; j++) {
			if (boo[s[i] - '0'][s[j] - '0'] == 1)continue;
			boo[s[i] - '0'][s[j] - '0'] = 1;
			ans += vec[j];
		}
	}
	cout << ans;
}

