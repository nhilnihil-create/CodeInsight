#include<bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<n;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define yesno(flg) if(flg){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define MAX_N 1002
#define i197 1000000007
#define Vi vector<int>
#define Vl vector<long long>
#define pb(a) push_back(a)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P1;
typedef pair<int,int> Pi;
typedef pair<double,Pi> Pdi;
typedef pair<ll,int>Pli;
typedef pair<P1,ll> P2;
const ll INF=10000000000000000001;
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
struct Road{double cost;int a,b;};
struct edge{int to,cost;};
struct pos{
	int x,y,cost;
};

int main() {

	ll a,b,v,w,t;
	cin>>a>>v;
	cin>>b>>w;
	cin>>t;

	if(a>b){
		if(a-v*t<=b-w*t)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}else{
		if(a+v*t>=b+w*t)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}

	return 0;
}
