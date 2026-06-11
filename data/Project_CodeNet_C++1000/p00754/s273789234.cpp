#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a)  (a).begin(),(a).end()
#define vi vector<int>
#define pb push_back
#define INF 999999999
//#define INF (1LL<<59)

int main(){
	string s;
	while(getline(cin,s)&&s!="."){
		bool res = true;
		stack<char> st;
		rep(i,s.size()){
			if(s[i]=='(' || s[i]=='[')st.push(s[i]);
			if(s[i]==')'){
				if(st.size()&&st.top()=='(')st.pop();
				else {res=false;break;}
			}
			if(s[i]==']'){
				if(st.size()&&st.top()=='[')st.pop();
				else {res=false;break;}
			}
		}
		
		if(st.size()==0&&res)cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
}