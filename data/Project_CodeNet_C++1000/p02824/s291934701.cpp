#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rep2(i,j,k) for(int i=j;i>=k;i--)
using namespace std;
template<typename T> void read(T &num){
	char c=getchar();T f=1;num=0;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	num*=f;
}
template<typename T> void qwq(T x){
	if(x>9)qwq(x/10);
	putchar(x%10+'0');
}
template<typename T> void write(T x){
	if(x<0){x=-x;putchar('-');}
	qwq(x);putchar('\n');
}
int co[100010];int in[100010]; 
int n,m,v,p;
inline bool check(int mid){
	memset(in,0,sizeof(in));
	int ba=co[mid]+m;long long tot=1ll*m*v;
	if(mid<=v){tot-=1ll*mid*m;}
	else{tot=0;}
	rep(i,mid+1,n){
		if(co[i]>=ba)break;
		if(tot>=ba-co[i]){tot-=ba-co[i];in[i]=ba-co[i];}
		else{in[i]=tot;tot=0;}
	}
	rep2(i,n,mid+1){
		if(tot>=m-in[i]){tot-=m-in[i];in[i]=m;}
		else{in[i]+=tot;break;}
	}
	int cnt=0;
	rep(i,1,n)cnt+=(co[i]+in[i]>ba);
	return cnt<=p-1;
}

int main(){
	read(n);read(m);read(v);read(p);
	rep(i,1,n)read(co[i]);
	sort(co+1,co+n+1);
	
	int l=1;int r=n;int ans=n+1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){ans=mid;r=mid-1;}
		else{l=mid+1;}
	}
	write(n-ans+1);
	return 0;
}