#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <string>
#include <algorithm>
#include <string>
#include <climits>

#define REP(i, n) for (int (i) = 0; (i) < (int)(n); (i)++)
#define REG(i, a, b) for (int (i) = ((int)(a)); (i) < ((int)(b)); i++)
#define ALL(V) (V).begin(), (V).end()
#define PRINT(STR) cout << (STR) << endl

typedef long long ll;
using namespace std;

int main() {
	char stc[1024];
	int counter = 0;
	string str;
	while (str = "", getline(cin, str), str != ".") {
		counter = 0;
		bool flag = true;
		REP(i, str.size()) {
			if (flag == false ) break;
			if (str[i] == '[' || str[i] == '(') {
				stc[counter++] = str[i];
			} else if (str[i] == ']') {
				if (counter == 0 || stc[--counter] != '[') {
				  flag = false;
				}
			} else if (str[i] == ')') {
				if (counter == 0 || stc[--counter] != '(') {
				  flag = false;
				}
			}
		}
		if (counter == 0 && flag == true) {
			PRINT("yes");
		} else {
			PRINT("no");
		}
	}
	return 0;
}