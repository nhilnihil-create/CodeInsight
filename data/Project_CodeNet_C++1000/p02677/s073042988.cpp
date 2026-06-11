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
const double pi=3.1415926535;

int main() {

	double a,b,h,m;
	cin>>a>>b>>h>>m;

	double c=abs(30*h+0.5*m-6*m);
	c=c*pi/180;
	double ans=a*a+b*b-2*a*b*cos(c);
	ans=sqrt(ans);
	cout<<setprecision(12)<<ans<<endl;

	return 0;
}
