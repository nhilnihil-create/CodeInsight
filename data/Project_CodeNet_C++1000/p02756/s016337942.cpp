#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
#define pb push_back
#define fi first
#define se second
const ll mod = 1e9+7;
const int N = 2e5+6;
void solve(){
	string s; 
	cin>>s; 
	deque<char> dq;
	for(char c:s)dq.push_back(c);
	int q; 
	cin>>q;
	int ord = 0;
	while(q--){
		int t; 
		cin>>t;
		if(t==1){
			ord = 1-ord;
		}
		else{
			int f;
			cin>>f; 
			char c;
			cin>>c;
			if(f==1){
				if(ord)dq.push_back(c);
				else dq.push_front(c);
			}
			else{
				if(ord==0)dq.push_back(c);
				else dq.push_front(c);
			}
		}
	}
	while(!dq.empty()){
		if(ord==0){
			cout<<dq.front();
			dq.pop_front();
		}
		else{
			cout<<dq.back();
			dq.pop_back();
		}
	}
	cout<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t=1; 
//	cin>>t; 
	while(t--){
		solve();
	}
	return 0;
}
