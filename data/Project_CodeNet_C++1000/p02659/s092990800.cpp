#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
using namespace std;

#define INF 0x3f3f3f3f
#define eps 1e-8

typedef long long ll;
const int MAXN = 1010;

 int main() {
 	unsigned long long a, b;
 	char str[5];
 	cin >> a >> str;
 	b = 0;
 	bool flag = false;
 	int cnt = 0;
 	for (int i=0; str[i]; i++) {
 		if (str[i] == '.') {
 			flag = true;
 			continue;
		} 
 		b = b*10+str[i]-'0';
 		if (flag)
 			cnt++;
	}
	 
	unsigned long long c = 1;
	while (cnt--)
		c *= 10;
	cout << a*b/c << endl;
	return 0;
 }