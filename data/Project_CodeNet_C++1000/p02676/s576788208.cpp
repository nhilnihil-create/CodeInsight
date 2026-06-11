#include<iostream>
using namespace std;

int main(void){
	int k;
	string s;
	cin >> k >> s;

	if (k >= (int)s.length()) cout << s;
	else {
		for (int i = 0;i < k;i++) {
			cout << s[i];
		}
		cout << "...";
	}
	return 0;
}