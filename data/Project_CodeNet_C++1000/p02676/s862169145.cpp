#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h> 
#include <stack>
#include <bitset>
#include <map>
#include <cmath>
#include <climits>
#include <queue>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
	int k;
	string str;
	cin >> k >> str;
	if (str.size() > k) cout << str.substr(0, k) << "..." << endl;
	else cout << str << endl;
}