#include <bits/stdc++.h>
using namespace std;
long long MOD=1e9+7;
long long p2[100005], p3[100005], pos[100005];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	p2[0]=p3[0]=1;
	for(int i=1;i<100005;i++){
		p2[i]=(p2[i-1]*2)%MOD;
		p3[i]=(p3[i-1]*3)%MOD;
	}
	string s;
	cin>>s;
	int n=s.size(), cnt=0;
	for(int i=0;i<n;i++){
		if(s[i]=='1') pos[cnt++]=i;
	}
	long long ans=0;
	for(int i=0;i<cnt;i++){
		ans=(ans+(p2[i]*p3[n-pos[i]-1]))%MOD;
	}
	ans=(ans+p2[cnt])%MOD;
	cout<<ans;
}