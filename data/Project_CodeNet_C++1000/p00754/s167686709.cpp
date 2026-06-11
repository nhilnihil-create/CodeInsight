#define _USE_MATH_DEFINES 
#include <iomanip> 
#include <cmath>  
#include<iostream>
#include <fstream>
#include<vector>
#include<algorithm>
#include<bitset>
#include<map>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define repi(i,a,b) for(ll i = (ll)(a) ; i < (ll)(b) ; i++)
#define repd(i,a,b) for(ll i = (ll)(a) ; i > (ll)(b) ; i--)
#define rd(x) cin >> x
#define wr(x)  cout << x
#define wrln(x) cout << x << endl


int main() {
	while (1) {
		string input;
		stack<char> st;
		getline(cin, input);
		if (input.length() == 1 && input[0] == '.')break;
		repi(i, 0, input.length()) {
			char ch = input[i];
			if (ch == '(' || ch == '[') st.push(ch);
			if (ch == ')' || ch == ']') {
				if (st.size() == 0 || (st.top()=='(' && ch== ']') || (st.top() == '[' && ch == ')')) {
					wrln("no");
					break;
				}
				else {
					st.pop();
				}
			}
			if (i == input.length() - 1) {
				if (st.size() == 0) wrln("yes");
				else wrln("no");
			}
		}
	}
	return 0;
}
