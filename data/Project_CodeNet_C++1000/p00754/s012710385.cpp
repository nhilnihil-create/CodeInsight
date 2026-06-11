#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
#include <set>
#include <utility>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <numeric>
#include <sstream>
#include <list>
#include <map>
#include <functional>
#include <iterator>

#define rep(i,p,n) for(int i=(int)p;i<(int)n;i++)
#define repp(i,p,n) for(int i=(int)p;i>=(int)n;i--)
#define Sort(x) sort(x.begin(),x.end())
#define PSort(x) sort(begin(x), end(x), pairCompare)
#define ll long long
#define INF 2000000000
#define pb push_back
#define mp make_pair
#define PI 3.14159265358979

using namespace std;

int main() {
	while (1) {
		stack<char> st;
		string s;
		getline(cin, s);

		bool start = true;
		bool f = false;
		if (s == ".") {
			break;
		}

		bool judge = true;
		rep(i, 0, s.length()) {
			if (s[i] == '(' || s[i] == '[' || s[i] == ']' || s[i] == ')') {
				judge = false;
			}
		}
		if (judge) {
			cout << "yes" << endl;
			continue;
		}
		rep(i, 0, s.length()) {
			if (s[i] == '(') {
				if (start) {
					start = false;
				}
				st.push('(');
			}
			else if (s[i] == '[') {
				if (start) {
					start = false;
				}
				st.push('[');
			}
			else if (s[i] == ')') {
				if (!st.empty()) {
					if (st.top() != '(') {
						break;
					}
					else st.pop();
				}
				else {
					f = true;
					break;
				}
			}
			else if (s[i] == ']') {
				if (!st.empty()) {
					if (st.top() != '[') {
						break;
					}
					else st.pop();
				}
				else {
					f = true;
					break;
				}
			}
		}
		if (st.empty() && !f)cout << "yes" << endl;
		else cout << "no" << endl;
	}

	

	return 0;
}