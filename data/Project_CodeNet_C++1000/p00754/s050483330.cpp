#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
#define FOR(i,s,n) for(int i=s; i<n; i++)
#define ALL(x) x.begin(), x.end()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
	string in;
	while(getline(cin, in), in!=".") {
		string stk = "";
		bool ok = true;
		rep(i, in.length()) {
			if( in[i] == '(' ) {
				stk += ')';
			} else if( in[i] == '[' ) {
				stk += ']';
			}
			else if( in[i] == ')' || in[i] == ']' ) {
				if( stk.length()>0 && stk[stk.length()-1] == in[i] ) {
					stk = stk.substr(0, stk.length()-1);
				} else {
					ok = false;
					break;
				}
			}
		}
		if(ok) {
			cout << (stk.length() == 0 ? "yes" : "no") << endl;
		} else {
			cout << "no" << endl;
		}
	}
	return 0;
}