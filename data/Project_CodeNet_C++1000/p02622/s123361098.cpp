#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define endl "\n"
#define goat() ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);srand(time(NULL))
typedef long long ll;
string lower(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 65 && s[i] <= 92) {
			s[i] += 32;
		}
	}
	return s;
}
ll arr[100][100];
int main() {
	goat();
	int n, i, c = 0;
	string s, t;
	cin >> s >> t;
	n = s.length();
	for (i = 0; i < n; i++) {
		if (s[i] != t[i]) {
			c++;
		}
	}
	cout << c;
}