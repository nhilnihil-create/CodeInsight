#include <iostream>
#include <stdio.h>
using namespace std;
  
int main()
{
	int n, a, b;
	string str, strl, strr, cmd, p;
	
	cin >> str;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> cmd >> a >> b;
		if (cmd == "replace") {
			strl.clear();
			strr.clear();
			cin >> p;
			for(int j = 0; j < a; j++)
				strl += str[j];
			strr = str.substr(b+1);
			str = strl + p + strr;
		}
		else if (cmd == "reverse") {
			strl.clear();
			p.clear();
			strr.clear();
			for(int j = 0; j < a; j++)
				strl += str[j];
			for(int j = b; j >= a; j--)
				p = p + str[j];
			strr = str.substr(b+1);			
			str = strl + p + strr;
		}
		else if (cmd == "print") {
			for(int j = a; j <= b; j++)
				cout << str[j];
			cout << endl;
		}
	}
	return 0;
}