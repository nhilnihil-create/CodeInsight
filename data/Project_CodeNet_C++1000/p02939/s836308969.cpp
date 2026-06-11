#include<bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	int res = 1;
	int pre = 1;
	for (int i = 1; i < s.size(); i++)
	{
		if(pre == 2 || s[i] != s[i-1]) {
			res++;
			pre = 1;
		}
		else {
			if(i == s.size()-1) continue;
			res++;
			pre = 2;
			i++;
		}
	}
	cout << res << endl;
	return 0;
}
