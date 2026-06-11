#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int n, k;
string s;
stack<int> st;
int main() {
	int i, j, fl;
	cin >> n >> k >> s;
	for(i=n; i; ) {
		fl = 0;
		for(j=min(i, k); j; j--) {
			if(s[i-j] == '0') {
				i -= j;
				st.push(j);
				fl = 1;
				break;
			}
		}
		if(!fl) return puts("-1")*0;
	}
	while(!st.empty()) printf("%d ", st.top()), st.pop();
	return 0;
}