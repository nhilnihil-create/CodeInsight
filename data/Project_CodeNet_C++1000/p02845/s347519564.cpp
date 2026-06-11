#include<cstdio>
#include<cstring>
#include<iostream>
#define in inline
#define re register
#define int long long
#define M 1000000007
using namespace std;
in int read() {
	re int t=0;
	re char v=getchar();	
	while(v<'0'||v>'9'){
	v=getchar();
	}	
	while(v>='0'&&v<='9'){		
	t=(t<<3)+(t<<1)+(v^48);		
	v=getchar();	}
	return t;
}
int f[100002],a[100002],b,c,d,cnt[100002],n;
signed main(){
n=read();
for(re int i=1;i<=n;++i)a[i]=read();
f[0]=1;
for(re int i=1;i<=n;++i){
	if(a[i]==0)f[i]=f[i-1]*(3-cnt[0]);
	else f[i]=f[i-1]*(cnt[a[i]-1]-cnt[a[i]]);
	f[i]%=M;
	++cnt[a[i]];
}
cout<<f[n];
}
