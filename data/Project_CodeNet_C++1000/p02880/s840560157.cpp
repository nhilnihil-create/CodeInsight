#include <iostream>
#include <stdio.h>

#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <climits>

using namespace std;


int main(){
	int n;
	cin >> n;

	bool frag = false;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			if (i * j == n) frag = true;
		}
	}
	
	if (frag)cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}