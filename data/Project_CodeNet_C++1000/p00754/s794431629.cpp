#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstdio>
#define F(i,n) for(int i=0;i<(int)(n);i++)
#define INF 100000000
#define ll long long

using namespace std;
typedef pair<int, int> P;

int main() {
	string a;
	int ans,i,j,p=0;
	stack<int> s;
	while (1) {
		ans = 0;
		i = 0;
		while (s.size()!=0) {
			s.pop();
		}
		getline(cin, a);
		F(j,100) {
			if (i == 0 && a[j] == '.') {
				p = 1;
				break;
			}
			if (a[j] == '.') {
				if (s.size()!=0 ){
					ans = 1;
					break;
				}
				break;
			}
			if (a[j] == '(')s.push(1);
			if (a[j] == '[')s.push(2);
			if (a[j] == ')') {
				if (s.size() == 0) {
					ans = 1;
					break;
				}
				if (s.top() == 1) {
					s.pop();
				}
				else {
					ans = 1;
				}
			}
			if (a[j] == ']') {
				if (s.size() == 0) {
					ans = 1;
					break;
				}
				if (s.top() == 2) {
					s.pop();
				}
				else {
					ans = 1;
					break;
				}
			}
			i = 1;

		}
		if (p == 1)break;
		if (ans == 0)cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}