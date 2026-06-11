#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcountll

#define INF 1e16
#define mod 1000000007

ll N,M,V,L;
vector<ll> A;

bool ok(ll X){
	ll mx=A[X]+M;
	ll upcnt=0;
	rep(i,N){
		if(i==X)continue;
		if(A[i]>mx)upcnt++;
	}
	//dbg(upcnt);
	if(upcnt>=L)return false;
	ll rest=V-1-upcnt;
	if(rest<=0)return true;
	//dbg(rest); dbg(mx);
	ll restsum=rest*M;
	//dbg(restsum);
	for(ll i=N-1;i>=0;i--){
		if(i==X)continue;
		if(A[i]<=mx){
			if(upcnt+1<L){
				restsum-=M;
				upcnt++;
			}else{
				restsum-=min(M,mx-A[i]);
			}
		}
	}
	if(restsum<=0)return true;
	else return false;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin>>N>>M>>V>>L;
  A.resize(N);
  rep(i,N)cin>>A[i];
  sort(all(A));
  /*rep(i,N){
  	cout<<A[i]<<" ";
  }
  cout<<endl;*/

  ll lb=-1,ub=N;
  while(ub-lb>1){
  	ll mid=(lb+ub)/2;
  	if(ok(mid)) ub=mid;
  	else lb=mid;
  }
  cout<<N-ub<<endl;

  return 0;
}
