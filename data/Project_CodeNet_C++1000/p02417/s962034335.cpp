#define _USE_MATH_DEFINES 
#include <cmath>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
#include<cctype>
#define rep(i,start,n) for(int i=start;i<n;i++)
#define And &&
#define Or ||
#define Lb cout<<endl
using namespace std;

int main(void) {
	char ch;
	int number[26] = {};
	while (cin >> ch) {
		ch = tolower(ch);
			number[ch - 'a']++;
	}
	rep(i, 0, 26) {
		cout << (char)('a' + i) << " : " << number[i] << endl;
	}
}