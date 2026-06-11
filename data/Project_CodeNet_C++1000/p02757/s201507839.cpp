#include<bits/stdc++.h>
using namespace std;
char s[200000+7];
long long  mp[200000+7];
int main(){
	long long  n,p;
	cin>>n>>p;
	cin>>s+1;
	if(p==2||p==5){
		long long  ans=0;
		for(long long i=n;i>=1;i--){
			if((s[i]-'0')%p==0){
				ans+=i; 
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	long long ans=0;
	long long  t=1,tmp=0;
	mp[0]++;
	for(int i=n;i>=1;i--){
		tmp=(tmp+(s[i]-'0')*t)%p;
		mp[tmp]++;
		t=t*10%p;
	}
	for(int i=0;i<=p;i++) {
		ans+=(mp[i]-1)*(mp[i])/2;
	}
	cout<<ans<<endl;
	return 0;
}