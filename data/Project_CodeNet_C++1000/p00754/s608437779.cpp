#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>

using namespace std;

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define EPS 1e-14

#define all(v) v.begin(),v.end()
// #define INF
// #define mp
// #define pb

// #define fi
// #define se

// #define each

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

typedef long long ll;

int main(){
	while(1){
		stack <char> st;
		string s = "";
		char q;
		q = getchar();
		//cout<<q<<endl;
		if(q=='\n'){
			q = getchar();
			if(q=='.'){
				return 0;
			}
		}
		
		s += q;

		while(1){
			string c;
			cin>>c;
			if(c[c.size()-1]!='.') s+= (' '+c);
			else{
				s += (' '+c);
				break;
			}
		}
		//cout<<s<<endl;
		if(s[0]=='.'&& s.size()==1) break;
		rep(i,s.size()){
			switch(s[i]){
				case '[': st.push('[');
				break;
				case '(': st.push('(');
				break;
				case ']': 
					if(st.empty()){
						cout << "no" << endl;
						goto END;
					}
					if(st.top()!='['){
						cout << "no" << endl;
						goto END;
					}else{
						st.pop();
					}
				break;
				case ')':
					if(st.empty()){
						cout << "no" << endl;
						goto END;
					}
					if(st.top()!='('){
					cout << "no" << endl;
					goto END;
					}else{
						st.pop();
					}
				break;
			}
		}
		if(!st.empty()) cout <<"no"<<endl;
		else cout << "yes"<<endl;
		END:;
	}
	return 0;
}