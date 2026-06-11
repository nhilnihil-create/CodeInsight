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

vector<ll> A,sum;
ll N;

bool ok(ll X,ll K){
  ll idx=lower_bound(all(A),X)-A.begin();
  ll tot=sum[idx]+(N-idx)*X;
  return tot>=X*K;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin>>N;
  A.resize(N);
  sum.resize(N+1);
  rep(i,N){
    ll a;
    cin>>a;
    a--;
    A[a]++;
  }
  sort(all(A));
  rep(i,N)sum[i+1]=sum[i]+A[i];

  repl(K,1,N+1){
    ll lb=-1,ub=N+1;
    while(ub-lb>1){
      ll mid=(ub+lb)/2;
      if(ok(mid,K))lb=mid;
      else ub=mid;
    }
    cout<<lb<<"\n";
  }
  return 0;
}
