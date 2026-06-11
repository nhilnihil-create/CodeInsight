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
	int n, cnt = 0;
	string str;
	map<string, int> dic;
	scanf("%d", &n);
	rep(i, n) {
		cin >> str;
		dic[str] = 0;
	}
	for (auto i : dic) cnt++;
	printf("%d", cnt);
}