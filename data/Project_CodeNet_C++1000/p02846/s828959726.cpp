#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll MOD=1e9+7;
const ll N=2e5+5;
const ld pi=3.14159265359;
const ll INF=(1LL<<63);
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define setp setprecision
#define lwb lower_bound
#define SZ(a) (ll)a.size()

ll t[2],a[2],b[2],A,B;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	REP(i,2)cin>>t[i];
	REP(i,2)cin>>a[i];
	REP(i,2)cin>>b[i];
	A=(a[0]-b[0])*t[0];B=(a[1]-b[1])*t[1];
	if(A>0)A*=-1,B*=-1;
	if(A+B<0)cout<<"0\n";
	else if(A+B==0){
		cout<<"infinity\n";
	}else{
		ll S=-A/(A+B);
		ll T=-A%(A+B);
		if(T!=0){
			cout<<S*2+1<<"\n";
		}else cout<<S*2<<"\n";
	}
	return 0;
}


