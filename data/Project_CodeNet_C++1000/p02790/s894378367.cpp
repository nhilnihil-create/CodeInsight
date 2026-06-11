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
	int a, b;
	cin >> a >> b;
	if (a > b) {
		for (int i = 0;i < a;i++) {
			printf("%d", b);
		}
	}
	else {
		for (int i = 0;i < b;i++) {
			printf("%d", a);
		}
	}

	return 0;
}

//AAAAAAAAAAAAAAAAA
//int main() {
//	int n, m;
//	cin >> n >> m;
//
//	if (n == m) {
//		cout << "Yes" << endl;
//	}
//	else {
//		cout << "No" << endl;
//	}
//	
//	return 0;
//}