#include<bits/stdc++.h>
using namespace std;

int main(){
	char s[4];
	for(int i=0;i<4;i++) cin >> s[i];
	cout << ((s[0]==s[1] | s[1]==s[2] | s[2]==s[3])? "Bad": "Good") << endl;
	return 0;
}