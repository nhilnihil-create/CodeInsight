#include<bits/stdc++.h>
using namespace std;
 
#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define SORT(c) sort((c).begin(),(c).end())
#define IINF INT_MAX
#define LLINF LLONG_MAX
#define DEBUG false
 
typedef long long ll;
typedef pair<int, int> ii;

#define MAXI 1000000

int main() {

	string s;
	while(getline(cin, s), s != "."){
		stack<int> st;
		bool flag = true;
		rep(i, s.size()){
			if(s[i] == '(') st.push(1);
			if(s[i] == '[') st.push(2);
			if(s[i] == ')'){
				if(st.empty() || st.top() != 1){
					flag = false;
					break;
				}
				st.pop();
			}
			if(s[i] == ']'){
				if(st.empty() || st.top() != 2){
					flag = false;
					break;
				}
				st.pop();
			}
		}
		if(flag && st.empty()) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	

	return 0;
}