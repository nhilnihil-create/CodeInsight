#include<bits/stdc++.h>
using namespace std;
#define re register
#define int long long
inline int read(){
	re int t=0;
	re char v=getchar();
	while(v<'0'||v>'9')v=getchar();
	while(v>='0'&&v<='9'){
		t=(t<<3)+(t<<1)+(v^48);
		v=getchar();
	}
	return t;
}
int n,a[100002],m,p,v,l,r;
signed main(){
	n=read();
	m=read();
	v=read();
	p=read();
	for(re int i=1;i<=n;++i)a[i]=read();
	sort(a+1,a+n+1);
	l=1,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		int tmp=a[mid]+m,num=m*(v-mid),cnt=mid;
		while(cnt<=n&&tmp>=a[cnt]){
			++cnt;
			if(tmp>=a[cnt]&&cnt<=n)
			num-=(tmp-a[cnt]);
		}
		num-=(n-cnt+1)*m;
		while(num>0&&cnt>=1)--cnt,num-=m-(tmp-a[cnt]);
		//cout<<cnt<<endl;
		//cout<<l<<" "<<r<<" "<<tmp<<" "<<mid<<" "<<a[mid]<<" "<<cnt<<endl;	
		if(cnt>n-p+1)r=mid;
		else l=mid+1;
	}
	printf("%lld",n-r+1);
}
