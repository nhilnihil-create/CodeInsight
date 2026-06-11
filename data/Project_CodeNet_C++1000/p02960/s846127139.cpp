#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string s;
	cin >> s;
	vector<ll>ans(13,0);
	vector<ll>ansbu = ans;
	vector<ll>anszero = ans;
	if (s.at(0) == '?') {
		for (int i = 0; i < 10; i++) ans.at(i)++;
	}
	else ans.at(s.at(0) - '0')++;
	for (int i = 1; i < s.length(); i++) {
		//10倍phase
		for (int j = 0; j < 13; j++) ansbu.at((j * 10) % 13) += ans.at(j);
		ans = ansbu;
		ansbu = anszero;
		//追加phase
		if(s.at(i)=='?'){
			for (int j = 0; j < 13; j++) {
				for (int k = 0; k < 10; k++) {
					ansbu.at((j + k) % 13) += ans.at(j);
				}
			}
		}
		else {
			for (int j = 0; j < 13; j++)ansbu.at((j + (s.at(i) - '0')) % 13) += ans.at(j);
		}
		ans = ansbu;
		ansbu = anszero;
		//mod
		for (int j = 0; j < 13; j++)ans.at(j) %= 1000000007;
	}
	cout << ans.at(5) << endl;
}