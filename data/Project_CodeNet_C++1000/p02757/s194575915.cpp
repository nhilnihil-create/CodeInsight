#include <bits/stdc++.h>
using namespace std;
#define int long long int
int cnt[10005];
int po[200005];
main() {
	
	int n, p;
	cin>>n>>p;
	po[0]=1;
	for(int i=1; i<200005; i++){
		po[i]=(po[i-1]*10)%p;
	}
	string s;
	cin>>s;
	if(p==2){
		int ans=0;
		for(int i=0; i<s.size(); i++){
			if(((s[i]-'0'))%2==0){
				ans+=(i+1);
			}
		}
		cout<<ans;
		return 0;
	}
	if(p==5){
		int ans=0;
		for(int i=0; i<s.size(); i++){
			if(((s[i]-'0'))%5==0){
				ans+=(i+1);
			}
		}
		cout<<ans;
		return 0;
	}
	int ans=0;
	int curr=0;
	cnt[0]=1;
	for(int i=s.size()-1; i>=0; i--){
		curr=((curr)+(s[i]-'0')*po[s.size()-1-i])%p;
		ans+=cnt[curr];
		
		cnt[curr]++;
	}
	cout<<ans;
	return 0;
}