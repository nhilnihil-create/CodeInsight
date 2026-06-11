#include<bits/stdc++.h>
using namespace std;

int main(){
	char s[5];
	for (int i = 0; i<4; i++) cin >> s[i];
	sort(s,s+4);
	cout << ((s[0]==s[1] && s[0]!=s[2] && s[2]==s[3])? "Yes" : "No") << endl;
	
	return 0;
}