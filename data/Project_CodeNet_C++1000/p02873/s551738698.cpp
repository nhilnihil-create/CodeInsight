#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;  cin >> s;
	int len = s.size();
	vector<int> t(len+1, 0);
	for(int i=0; i<len; i++)
		if(s[i] == '<')
			t[i+1] = t[i] + 1;
	for(int i=len-1; i>=0; i--)
		if(s[i] == '>')
			t[i] = max(t[i], t[i+1] + 1);
	long ans = 0;
	for(int i=0; i<=len; i++)
		ans += (long)t[i];
	
	cout << ans << endl;
	return 0;
}