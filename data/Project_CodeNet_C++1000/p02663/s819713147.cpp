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

	int h1,m1,h2,m2,k;
	cin>>h1>>m1>>h2>>m2>>k;

	h1=h1*60+m1;
	h2=h2*60+m2;
	h1=h2-h1;
	cout<<h1-k<<endl;

	return 0;
}
