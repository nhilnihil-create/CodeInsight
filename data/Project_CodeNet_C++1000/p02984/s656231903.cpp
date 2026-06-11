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
ll a[100001];

int main() {

	int n;
	cin>>n;

	rep(i,n)cin>>a[i];

	ll x=a[n/2],m=a[0],u=a[n-1];
	for(int i=1; i<n/2; i++)m=a[i]-m;
	for(int i=n-2; i>n/2; i--)u=a[i]-u;
	x=x-m-u;

	if((n-1)%4==0)x/=2;
	else x/=-2;

	cout<<2*x<<" ";
	for(int i=0; i<n-2; i++){
		x=a[i]-x;
		cout<<2*x<<" ";
	}
	cout<<2*(a[n-2]-x)<<endl;

	return 0;
}
