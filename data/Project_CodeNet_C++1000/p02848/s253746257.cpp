#include<iostream>
//#include<stdio.h>
#include<string>
//#include<typeinfo>
//#include<sstream>
//#include<algorithm>
using namespace std;

int main(void) {
	int N;
	string str;
	string strResult = "";
	cin >> N;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		int x = str[i] - 'A';
		x = (x + N) % 26;
		printf("%c", x + 'A');
	}

	return 0;
}
