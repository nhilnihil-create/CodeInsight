#pragma GCC optimize(2,3)
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define re register
#define int long long
using namespace std;
int n,m,k,ans,a[1000002];
char s[1000002];
signed main(){
scanf("%s",s+1);
n=strlen(s+1);
for(re int i=1;i<=n;++i)a[i]=s[i]-'0';
for(re int i=n;i>=1;--i){
	if(a[i]>=10){
		a[i-1]+=a[i]/10;
		a[i]%=10;
	}
if(a[i]<5)ans+=a[i];
else if(a[i]>5)ans+=10-a[i],++a[i-1];
else if(a[i-1]>=5){ans+=10-a[i],++a[i-1];
}
else ans+=a[i];
}
if(a[0]<=5)ans+=a[0];
else ans+=11-a[0];
cout<<ans<<endl;
}
