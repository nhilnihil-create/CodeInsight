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
	while (true) {
		string str;
		cin >> str;
		if (str == "-")break;
		int m; cin >> m;
		vector<int> h(m);
		rep(i, 0, m) {
			cin >> h[i];
		}
		rep(i, 0, m) {
			string sub, upper;
			sub = str.substr(0, h[i]);
			upper = str.substr(h[i], str.length()-h[i]);
			str = upper + sub;
		}
		cout << str<<endl;
	}

}