#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define repb(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define o(a) cout<<a<<endl
#define int long long
#define fi first
#define se second
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

signed main(){
	string s;
	while(1){
		getline(cin, s);
		if(s == ".") break;
		stack<char> st;
		bool f = true;
		rep(i, 0, s.size()){
			if(s[i]=='(' || s[i]=='['){
				st.push(s[i]);
			}
			if(s[i]==')' || s[i]==']'){
				char tmp;
				if(st.empty()){
					f=false; break;
				}
				tmp = st.top(); st.pop();
				if((s[i]==')' && tmp=='[')||(s[i]==']' && tmp=='(')){
					f=false; break;
				}
			}
		}
		if(f && st.empty()) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
}