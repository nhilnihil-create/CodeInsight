#include<bits/stdc++.h>
#include<iostream>
#define rep(i,n) for(int i=0;i<n;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define yesno(flg) if(flg){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define MAX_N 1002
#define i197 1000000007

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P1;
typedef pair<int,int> Pi;
typedef pair<double,Pi> Pdi;
typedef pair<ll,int>Pli;
typedef pair<int,ll>Pil;
typedef pair<int,Pil>Piil;
typedef pair<P1,ll> P2;
typedef pair<string,string> Ps;
const ll INF=1000000000000000001;
struct edge{int to,cost;};
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
struct Road{double cost;int a,b;};
struct pos{
	// 1 変数を入れる;
	int x,y,sx,sy,cost;
};
int l[100001]={},r[100001]={};

int main() {

	int n,k;
	string s;
	cin>>n>>k;
	cin>>s;

	int ls=0,rs=0;
	int c=1,f=0;
	int ans=0;
	for(int i=1; i<n; i++){
		if(s[i]==s[i-1])c++;
		else{
			ans+=c-1;
			c=1;
			if(s[i-1]=='L'){
				l[ls]=2;
				ls++;
				if(f==0)l[ls-1]--;
			}else{
				r[rs]=2;
				rs++;
				if(f==0)r[rs-1]--;
			}
			f=1;
		}
	}
	ans+=c-1;
	if(s[n-1]=='L'){
		l[ls]=1;
		if(f==0)l[ls]--;
		ls++;
	}
	else{
		r[rs]=1;
		if(f==0)r[rs]--;
		rs++;
	}
	sort(l,l+ls,greater<int>());
	sort(r,r+rs,greater<int>());

	int lc=0,rc=0;
	rep(i,min(k,ls))lc+=l[i];
	rep(i,min(k,rs))rc+=r[i];
	rc=max(rc,lc);
	cout<<ans+rc<<endl;

	return 0;
}
