#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
typedef long long ll;
#define I inline void
#define IN inline int
#define C(x,y) memset(x,y,sizeof(x))
#define STS system("pause")
template<class D>I read(D &res){
	res=0;register D g=1;register char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')g=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		res=(res<<3)+(res<<1)+(ch^48);
		ch=getchar();
	}
	res*=g;
}
char c[1010000];
int n,m,x,a[1010000],b[1010000],s[1010000],ans;
int main(){
	read(n);
	cin>>c+1;
	F(i,1,n)a[i]=c[i]-'0';
	if(n==1){
		cout<<c[1];return 0;
	}
	F(i,1,n-1)b[i]=abs(a[i]-a[i+1]);
	n--;
	F(i,1,n)a[i]=b[i];
	m=0;
	F(i,1,n)if(a[i]==1)m=1;
	if(!m){
		F(i,1,n)a[i]>>=1;
	}
	F(i,1,n){
		x=i;
		while(!(x&1))s[i]++,x>>=1;
		s[i]+=s[i-1];
	}
	ans=0;
	F(i,1,n){
		ans^=(s[n-1]-s[i-1]-s[n-i])?0:(a[i]&1);
	}
	if(!m)ans<<=1;
	cout<<ans;
	return 0;
}
