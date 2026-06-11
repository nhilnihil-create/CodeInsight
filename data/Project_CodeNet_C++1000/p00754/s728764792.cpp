#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
typedef unsigned int ui;
int main(){
	string s; int i, j;
	while (getline(cin, s)) {
		if (s == ".")break;
		bool f = true;
		int mark[100];
		int len = s.length();
		for (i = 0; i < len; i++) {
			if (s[i] == '(') {
				mark[i] = 1;
			}
			else if (s[i] == '[') {
				mark[i] = 2;
			}
			else if (s[i] == ')') {
				mark[i] = -1;
			}
			else if (s[i] == ']') {
				mark[i] = -2;
			}
			else mark[i] = 0;
		}
		for (i = 0; i < len; i++) {
			if (mark[i] < 0) {
				for (j = i - 1; j >= 0; j--) {
					if (mark[i] + mark[j] == 0) {
						mark[i] = mark[j] = 0; break;
					}
					else if (mark[j] != 0) {
						f = false; break;
					}
				}
				if (j == -1)f = false;
			}
		}
		for (i = 0; i < len; i++) {
			if (mark[i] != 0)f = false;
		}
		if (f)cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}
