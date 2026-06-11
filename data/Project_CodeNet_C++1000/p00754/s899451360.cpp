#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define rep(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define all(v) (v).begin(), (v).end()
#define rev(s) string((s).rbegin(), (s).rend())
#define MP make_pair
#define X first
#define Y second

using namespace std;

typedef long long int ll;
typedef pair<int, int> P;

int main(){

	char m[200];

	m[')'] = '(';
	m[']'] = '[';

	while(1){
		string s;
		getline(cin, s);
		if(s.size() == 1 && s[0] == '.')break;
		stack<char> st;
		rep(i, s.size()){
			if(s[i] == '(' || s[i] == '[') st.push(s[i]);
			if(s[i] == ')' || s[i] == ']'){
				if(st.size() < 1){
					st.push('a');
					break;
				}
				if(st.top() == m[s[i]]){
					st.pop();
				}else{
					break;
				}
			}
		}
		cout << (st.size()?"no":"yes") << endl;
	}

	return 0;
}