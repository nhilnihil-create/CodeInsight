#pragma GCC optimize("Ofast",3,"inline")
#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define m_p make_pair
#define y1 ygftgfgcdtfgxffgx
#define y2 yfdsesgvtyghftfvv
#define x1 xvyr6cf6fgcfgf676
#define x2 xcr6rfc5r66y6r6fr
#define up_bound upper_bound
#define low_bound lower_bound
#define next_per next_permutation
#define pb push_back
#define i_to_s to_string
typedef priority_queue<int> p_queue;
typedef priority_queue<int, vector<int>, greater<int> > min_p_queue;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int mon[20]={0,31,28,31,30,31,30,31,31,30,31,30,31};
ll gcd(ll x,ll y){return ((y==0)?x:gcd(y,x%y));}
inline int read(){
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x;
}
int d[200010][70];
ll n,k;
int a[200010];
bool w[100],b[100];
int t=1;
void run(int x){
	int a=x-1;
	for(int i=1;i<=n;i++)
		d[i][x]=d[d[i][a]][a];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)d[i][0]=a[i];
	for(int i=1;i<=62;i++)
		run(i);
//	int pos=0;
//	while(k){
//		w[pos++]=k&1;
//		k/=2;
//	} 
//	for(int i=pos-1;i>=0;i--)cout<<w[i];
//	for(int i=0;i<pos;i++)
//		b[pos-i-1]=w[i];
//	for(int i=0;i<pos;i++)
//		if(b[i])t=d[t][i];
	for(int i=62;i>=0;i--){
		ll l=1ll<<i;
		if(l<=k){
			t=d[t][i];
			k-=l;
		}
	} 
	cout<<t;
	return 0;
}

