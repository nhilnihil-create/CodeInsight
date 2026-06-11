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

int main() {

	int x;
	cin>>x;

	if(400<=x&&x<=599)cout<<"8"<<endl;
	else if(600<=x&&x<=799)cout<<"7"<<endl;
	else if(800<=x&&x<=999)cout<<"6"<<endl;
	else if(1000<=x&&x<=1199)cout<<"5"<<endl;
	else if(1200<=x&&x<=1399)cout<<"4"<<endl;
	else if(1400<=x&&x<=1599)cout<<"3"<<endl;
	else if(1600<=x&&x<=1799)cout<<"2"<<endl;
	else if(1800<=x&&x<=1999)cout<<"1"<<endl;

	return 0;
}
