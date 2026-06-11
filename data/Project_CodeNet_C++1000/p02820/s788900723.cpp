#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
int main(){
	ll n,k; cin>>n>>k;
	ll r,S,p; cin>>r>>S>>p;
	string s; cin>>s;
	vector<char> c(n);
	int ans=0;
	for(int i=0;i<n;i++){
		if(i<k){
			if(s[i]=='r') c[i]='p',ans+=p;
			else if(s[i]=='p') c[i]='s',ans+=S;
			else if(s[i]=='s') c[i]='r',ans+=r;
		}else{
			if(s[i]=='r'){
				if(c[i-k]!='p'){
					c[i]='p';
					ans+=p;
				}else{
					if(i+k>=n) c[i]='r';
					else {
						c[i]=s[i+k];
					}
				}
			}
			if(s[i]=='p'){
				if(c[i-k]!='s'){
					c[i]='s';
					ans+=S;
				}else{
					if(i+k>=n) c[i]='p';
					else {
						c[i]=s[i+k];
					}
				}
			}
			if(s[i]=='s'){
				if(c[i-k]!='r'){
					c[i]='r';
					ans+=r;
				}else{
					if(i+k>=n) c[i]='s';
					else {
						c[i]=s[i+k];
					}
				}
			}
		}
	}
//	for(char x:c) cout<<x; cout<<endl;
	cout<<ans;
}
