#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>
using namespace std;

int cul( int n1, int n2, string ss ) {
	int ret;
	if ( ss == "+" ) ret = n1 + n2;
	if ( ss == "-" ) ret = n1 - n2;
	if ( ss == "*" ) ret = n1 * n2;
	return ret;
}

int main() {
	stack<int> s;
	string st;
	int m1, m2;
	while ( cin >> st ) {
		if ( st == "+" || st == "-" || st == "*" ) {
			m2 = s.top();
			s.pop();
			m1 = s.top();
			s.pop();
			s.push( cul( m1, m2, st ) );
		} else {
			s.push( atoi( st.c_str() ) );
		}
	}
	cout << s.top() << endl;
}