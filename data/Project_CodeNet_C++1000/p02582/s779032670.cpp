#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	int c = 0;
	if(s[0] == 'R'){
		if(s[1] == 'R' && s[2] == 'R'){
			c = 3;
		}
		else if (s[1] == 'R' && s[2] != 'R'){
			c = 2;
		}
		else{
			c = 1;
		}

	}
	else if(s[1] == 'R'){
		if(s[2] == 'R'){
			c = 2;
		}
		else{
			c = 1;
		}
	}
	else if(s[2] == 'R'){
		c = 1;
	}
	cout << c;
}
