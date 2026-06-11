#include<bits/stdc++.h>
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
const ll INF=1000000000000000001;
struct edge{int to,cost;};
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
struct Road{double cost;int a,b;};

int main() {

	ll n;
	ll a,b,c,d;
	string s;

	cin>>n>>a>>b>>c>>d;
	cin>>s;
	for(int i=a-1; i<c-1; i++){
		if(s[i]=='#'&&s[i+1]=='#'){
			cout<<"No"<<endl;
			return 0;
		}
	}
	for(int i=b-1; i<d-1; i++){
		if(s[i]=='#'&&s[i+1]=='#'){
			cout<<"No"<<endl;
			return 0;
		}
	}
	if(c>d){
		for(int i=max(b-2,a); i<d-1; i++){
			if(s[i]=='.'&&s[i+1]=='.'&&s[i+2]=='.'){
				cout<<"Yes"<<endl;
				return 0;
			}
		}
		cout<<"No"<<endl;
	}
	if(c<d)cout<<"Yes"<<endl;
	return 0;

}
