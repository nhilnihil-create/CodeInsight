#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <array>
#include <map>
#include <queue>
#include <limits.h>
#include <set>
#include <bitset>
#include <stack>
#include <cstdlib>
#define REP(i,n) for(int i = 0; n > i; i++)
#define MOD 1000000007
using namespace std;
typedef vector<int> Ivec;
typedef pair<int, int> pii;
typedef long long int ll;
char str[101];
map<char, char> kako = { {'(',')'},{'[',']'} };
int is_balanced(int s) {
	for (int i = s+1; strlen(str) > i; i++) {
		if (str[i] == ')' || str[i] == ']') {
			if(str[i] != kako[str[s]])
				return -1;
			else {
				return i;
			}
		}
		if (str[i] == '(' || str[i] == '[') {
			i = is_balanced(i);
			if (i == -1) return -1;
		}
	}
	return -1;
}

int main() {
	while (1) {
		memset(str, 0, sizeof(str));
		for(int i = 0; ;i++) {
			scanf("%c", &str[i]);
			if (str[i] == '.') break;
		}
		scanf("%*c");
		if (!strcmp(str, "."))
			return 0;
		bool f = true;
		REP(i, strlen(str)) {
			if (str[i] == ')' || str[i] == ']') {
				printf("no\n");
				f = false;
				break;
			}
			if (str[i] == '(' || str[i] == '[') {
				i = is_balanced(i);
				if (i == -1) {
					printf("no\n");
					f = false;
					break;
				}
			}
		}
		if (f) printf("yes\n");
	}

	return 0;
}