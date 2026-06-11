#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt[214514];
int main(){
	string s;
	ll k;
	cin>>s>>k;
	ll ans=0,cnt=1,l=0,r=0;
	bool f=0,g=1;
	for(int i=1;i<s.size();i++){
		if(s[i-1]==s[i])cnt++;
		else{
			g=0;
			if(!f){
				l=cnt;
				f=1;
			}
			ans+=cnt/2;
			cnt=1;
		}
	}
	r=cnt;
	ans+=cnt/2;
	ans*=k;
	if(g)ans=s.size()*k/2;
	else if(s[0]==s[s.size()-1])ans+=((l+r)/2-l/2-r/2)*(k-1);
	cout<<ans;
	return 0;
}
