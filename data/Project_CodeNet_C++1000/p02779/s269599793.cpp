#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <queue>
#define rep(i,n) for (int i=0;i<(n);i++)

using namespace std;


int main() {
	int n;
	cin >> n;
	map<int, int> a;

	for (int i = 0;i < n;i++) {
		int j;
		cin >> j;
		a[j]++;
		if (a[j] == 2) {
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;
	return 0;
}
//BBBBBBBBBBBB
//int main(){
//	string s;
//	cin >> s;
//
//	for (int i = 0;i < s.length();i++) {
//		printf("x");
//	}
//
//	return 0;
//}

//AAAAAAAAAAAA
//int main() {
//	string s, t, u;
//	int a, b;
//	cin >> s >> t >> a >> b >> u;
//
//	if (s == u)a--;
//	else b--;
//
//	cout << a << " " << b << endl;
//	return 0;
//}