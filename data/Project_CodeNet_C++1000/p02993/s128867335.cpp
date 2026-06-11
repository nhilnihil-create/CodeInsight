#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	bool flag = 1;
	for(int i = 0;i < s.size()-1;++i)
		flag &= (s[i] != s[i+1]);
	cout << (flag ? "Good" : "Bad");
}
