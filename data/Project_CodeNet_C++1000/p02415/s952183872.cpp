#include<iostream>
#include<string>
using namespace std;
int main(){
	string s;
	getline(cin, s);
	int n = s.size();
	for (int i = 0; i < n; i++){
		if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a'&&s[i] <= 'z'))
			cout << (char)(s[i] ^ 32);
		else
			cout << s[i];
	}
cout <<endl;
	return 0;
}