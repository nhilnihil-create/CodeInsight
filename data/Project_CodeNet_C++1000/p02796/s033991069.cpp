#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int (i)=int (a);i<=int (b);i++)
#define ff(i,a,b) for(int (i)=int(a);i<int (b);i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
const double eps=1e-5;
const double pi=acos(-1.0);
const int N=1e6+6,inf=1<<30;
pii p[N];
int x[N],l[N];
int n;
int main(){
	scanf("%d",&n);
	ff(i,0,n){
		scanf("%d%d",x+i,l+i);
	}
	ff(i,0,n){
		p[i]={x[i]+l[i],x[i]-l[i]};
	}
	sort(p,p+n);
	int ans=0;
	int cur=-inf;
	ff(i,0,n){
		if(cur<=p[i].se){
			ans++;
			cur=p[i].fi;
		}
	}
	cout<<ans;
}