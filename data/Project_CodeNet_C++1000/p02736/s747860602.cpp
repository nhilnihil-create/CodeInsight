#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

int a[1000010],calc[1000010],pw2[1000010];

signed main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int val=0,p=i;
		while(p%2==0){
			p/=2;val++;
		}
		pw2[i]=pw2[i-1]+val;
	}
	for(int i=1;i<=n;i++){
		int cnt=pw2[n-1]-pw2[i-1]-pw2[n-i];
		if(cnt==0) calc[i]=1;
	}
	bool flag0=0,flag1=0,flag2=0;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		a[i]=c-'1';
		if(a[i]==0) flag0=1;
		if(a[i]==1) flag1=1;
		if(a[i]==2) flag2=1;
	}
	if(flag0&&flag1&&flag2){
		for(int i=1;i<=n;i++) if(a[i]==2) a[i]=0;
		int ans=0;
		for(int i=1;i<=n;i++) if(calc[i]) ans^=a[i];
		cout<<ans<<endl;
		return 0;
	}
	if(!flag0){
		if(!flag1){
			for(int i=1;i<=n;i++) a[i]-=2;
		}
		else{
			for(int i=1;i<=n;i++) a[i]--;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++) if(calc[i]) ans^=a[i];
	cout<<ans<<endl;
	return 0;
}