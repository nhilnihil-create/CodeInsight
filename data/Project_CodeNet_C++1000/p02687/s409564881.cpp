#include <iostream>
#include <string>

using namespace std;

int main(){
	string s = (char*)calloc(4, sizeof(char));
	cin >> s;
	if(s[1] == 'B') cout << "ARC";
	else cout << "ABC";
	cout << endl;
}