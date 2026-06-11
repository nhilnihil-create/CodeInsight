#include <iostream>
#include<string>
using namespace std;
int main(){
	string s, t;
	int a=0;
	cin >> s >> t;
	for (int i = 0; i <= s.size(); i++)
		if (s[i] != t[i])
			a++;
	cout << a;
}