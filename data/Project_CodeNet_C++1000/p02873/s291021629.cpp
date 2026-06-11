#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f(ll x){
	return (x-1)*x/2;
}
int main(){
	string s;
	cin>>s;
	s=">"+s;
	ll lc=0,rc=0;
	ll ans=0;
	for(int i=1;i<s.size();i++){
		if(s[i]=='>'){
			rc++;
			if(s[i-1]=='<')ans+=f(lc);
		}else{
			if(s[i-1]=='>'){
				ans+=max(rc,lc)+f(rc);
				lc=0;
				rc=0;
			}
			lc++;
		}
	}
	if(s[s.size()-1]=='<')ans+=f(lc+1);
	else {
		ans+=max(rc,lc)+f(rc);
	}
	cout<<ans;
	return 0;
}
