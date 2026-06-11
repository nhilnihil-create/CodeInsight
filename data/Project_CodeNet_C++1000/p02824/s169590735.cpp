#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define SZ(v) ((int)(v).size())
#define zero(v) memset(v,0,sizeof(v))
#define rep(i,n) for(int i=0;i<(n);i++)
#define foreach(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();it++)
#define all(v) (v).begin(),(v).end()
typedef long long ll;
typedef unsigned uint;
const int INF=0x3f3f3f3f;
int inline in(){int x=0,c;for(;(uint)((c=getchar())-'0')>=10;)
{if(c=='-')return -in();if(!~c)throw ~0;}do{x=(x<<3)+(x<<1)+(c-'0');}
while((uint)((c=getchar())-'0')<10);return x;}
int n,v,p;
ll m;
const int Maxn=1e5+5;
ll a[Maxn];
ll pre[Maxn];
bool check(int mid){
	if(mid<=p)return true;
	if(a[mid]+m<a[p])return false;
	int cnt=v-(p+n-mid);
	if(cnt<=0)return true;
	return cnt*m+(pre[mid-1]-pre[p-1])<=(a[mid]+m)*(mid-p);
}
int main(){
	cin>>n>>m>>v>>p;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=a[i]+pre[i-1];
	}
	int l=1,r=n+1;
	while(r-l>1){
		int mid=(l+r)/2;
		if(check(mid))l=mid;
		else r=mid;
	}
	cout<<l<<endl;
	return 0;
}