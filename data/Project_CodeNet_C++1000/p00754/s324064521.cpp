#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define REP(i,a,n) for(ll i=a;i<n;i++)
#define ALL(s) s.begin(),s.end()
#define P pair<ll,ll>
#define vl vector<ll>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vvl vector<vector<ll>>
#define print(n) cout<<n<<endl
const int M=100010;
const int inf=1000000007;
const long long INF=1000000000000000007;
using ll=long long;
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

int main(){
	while(1){
		bool ok=true;
		string s;
		while(1){
			char c;
			cin.get(c);
			s+=c;
			if(c=='\n')break;
		}
		if(s==".\n")break;
		int a=0,b=0;
		vector<char> v;
		rep(i,s.size()){
			if(s[i]=='(')a++,v.push_back('(');
			else if(s[i]==')'){
				a--;
				if(a<0||b<0){
					ok=false;
					break;
				}
				if(v[v.size()-1]=='(')v.pop_back();
				else ok=false;
			}
			else if(s[i]=='[')b++,v.push_back('[');
			else if(s[i]==']'){
				b--;
				if(a<0||b<0){
					ok=false;
					break;
				}
				if(v[v.size()-1]=='[')v.pop_back();
				else ok=false;
			}
		}
		if(a!=0||b!=0)ok=false;
		if(ok?print("yes"):print("no"));
	}



}
