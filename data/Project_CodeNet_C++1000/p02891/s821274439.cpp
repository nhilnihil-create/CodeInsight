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

	string s,t;
	ll k;
	ll total=0,c=1,t2=0;

	cin>>s;
	cin>>k;
	t=s+s;
	for(int i=1; i<t.size(); i++){
		if(i==s.size()){
			total+=t2;
			t2=0;
			if(c==s.size()){
				cout<<s.size()/2*(k/2+k%2)+(s.size()/2+s.size()%2)*(k/2)<<endl;
				return 0;
			}
		}
		if(t[i]==t[i-1])c++;
		if(t[i]!=t[i-1])c=1;
		if(c%2==0)t2++;
	}
	cout<<total+t2*(k-1)<<endl;
	return 0;

}
