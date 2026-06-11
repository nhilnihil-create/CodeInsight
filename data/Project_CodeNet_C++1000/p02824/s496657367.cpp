#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define SZ(v) ((int)(v).size())
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
bool check(int index){
	while(index>1&&a[index]==a[index-1]){
		index--;
	}
	if(index<=p)return true;
	int automatic=p+n-index;
//	cout<<automatic<<endl;
	if(automatic>=v){
		return a[index]+m>=a[p];
	}
	ll still_need_per_judge=v-automatic;
	ll still_to_add=m*still_need_per_judge;
	ll target=a[index]+m;
	for(int i=p;i<index;i++){
		ll take=min(m,target-a[i]);
		take=min(take,still_to_add);
		take=max(take,0LL);
		if(a[i]+take>target){
//			cout<<"prprpr"<<endl;
			return false;
		}
//		cout<<take<<' ';
		still_to_add-=take;
	}//cout<<endl;
//	cout<<still_to_add<<endl;
	return still_to_add==0;
}
int main(){
	cin>>n>>m>>v>>p;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
//	for(int i=1;i<=n;i++)cout<<a[i]<<' ';cout<<endl;
	int l=1,r=n+1;
	while(r-l>1){
		int mid=(l+r)/2;
//		cout<<l<<' '<<r<<' '<<mid<<endl;
		if(check(mid))l=mid;
		else r=mid;
	}
	cout<<l<<endl;
//	cout<<check(4)<<endl;
	return 0;
}