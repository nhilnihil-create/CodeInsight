#include<stdio.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

int main() {

	vector<string> s;
	
	while (1) {
		string ss;
		getline(cin, ss);
		if (ss == ".") break;

		int a[2] = {};
		bool flag = true;

		stack<int> st;
	
		for (int j = 0; j < ss.length(); j++) {

			if (ss[j] == '(') st.push(0),a[0]++;
			if (ss[j] == ')') {
				if (st.empty() || st.top() != 0 ) {
					flag = false;
					break;
				}
				else st.pop(),a[0]--;
			}
			if (ss[j] == '[') st.push(1),a[1]++;
			if (ss[j] == ']') {
				if (st.empty() || st.top() != 1) {
					flag = false;
					break;
				}
				else st.pop(), a[1]--;
			}
		}
		if (a[0] != 0 || a[1] != 0) flag = false;

		if (flag) cout << "yes" << endl;
		else cout << "no" << endl;

	}

	return 0;
}