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
int a[16];
int x[16][16],y[16][16];

int main() {

	int n;
	cin>>n;
	rep(i,n){
		cin>>a[i];
		rep(j,a[i])cin>>x[j][i]>>y[j][i];
	}
	int ans=0;
	for(int i=1; i<(1<<n); i++){
		int f=0,t=0;
		rep(j,n){
			if(i&(1<<j)){
				rep(k,a[j]){
					if(i&(1<<(x[k][j]-1))){
						if(y[k][j]==0)f=1;
					}else{
						if(y[k][j]==1)f=1;
					}
				}
				t++;
			}
			if(f==1)break;
		}
		if(f==0)ans=max(ans,t);
	}
	cout<<ans<<endl;

	return 0;
}
