#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se seoncd
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=100005;
int a[N],n,m,v,p;
ll s[N];

int chk(int x){
	int rem=v-x-p+1,t=n-p+1;
	return a[t]<=a[x]+m&&(ll)(t-x)*(a[x]+m)-(s[t]-s[x])>=(ll)rem*m;
}

int main(){
	read(n),read(m);
	read(v),read(p);
	rep(i,1,n) read(a[i]);
	sort(a+1,a+n+1);
	rep(i,1,n) s[i]=s[i-1]+a[i];
	int l=1,r=n-p+1,mid;
	while(l<r){
		mid=(l+r)>>1;
		if(chk(mid)) r=mid;
		else l=mid+1;
	}
	cout<<n-l+1<<endl;
	return 0;
}
