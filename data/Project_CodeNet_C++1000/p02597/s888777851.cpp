#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using ll = long long;

int main() {
	FASTIO
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
	int i = 0, j = n - 1;
	while(i < j){
		while(i < n && s[i] == 'R')
			i++;
		while(j >= 0 && s[j] == 'W')
			j--;
		if(i < j && s[i] == 'W' && s[j] == 'R')
			ans++, swap(s[i++], s[j--]);

	}
	cout << ans << endl;
}