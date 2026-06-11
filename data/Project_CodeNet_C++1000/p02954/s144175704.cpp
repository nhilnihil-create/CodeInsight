#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans[214514];
int main(){
	string s;
	cin>>s;
	ll rl,rr,ll,lr,now;
	rl=0,now=0;

	for(int i=1;i<s.size();i++){
		if(s[i]=='L'&&!now){
			rr=i-1;
			ll=i;
			now=1;
		}
		if(i==s.size()-1){
			lr=i;
			ans[rr]=(rr-rl+2)/2+(lr-ll+1)/2;
			ans[ll]=(rr-rl+1)/2+(lr-ll+2)/2;
		}
		if(s[i]=='R'&&now){
			lr=i-1;
			ans[rr]=(rr-rl+2)/2+(lr-ll+1)/2;
			ans[ll]=(rr-rl+1)/2+(lr-ll+2)/2;
			now=0;
			rl=i;
		}
	}
	for(int i=0;i<s.size();i++)cout<<ans[i]<<' ';
	return 0;
}
