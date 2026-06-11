#include <bits/stdc++.h>
using namespace std;
int main (){
	
	int n;
	cin >> n;
	string s;
	cin >> s;
	int num;
	for(int i=0;i<s.size();i++){
		num = int(s[i]);
		num = num + n;
		if (num > 90) num = num - 26;
		s[i] = char(num);
	}
	cout << s;
	return 0;
}