#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include<cstdio>
#include <vector>
#include<queue>
#include<limits.h>
#include<string.h>
#include<functional>
using namespace std;

signed main() {
	int a, b; 
	while (cin >> a >> b, a | b) {
		while (a--) {
			for (int c = 0; c < b; c++) {
				cout << '#';
			}
			puts("");
		}
		puts("");
	}
}