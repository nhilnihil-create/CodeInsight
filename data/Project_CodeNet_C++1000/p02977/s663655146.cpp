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

ll n;
vector<P> es;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin>>n;
  if(n==1){
    cout<<"No"<<endl;
    return 0;
  }

  for(ll i=1;i<(n%2==0?n-1:n);i+=2){
    es.push_back(P(0,i)); es.push_back(P(i,i+1));
    if(i==1)es.push_back(P(i+1,n));
    es.push_back(P(0,n+1+i)); es.push_back(P(n+1+i,n+i));
  }

  if(n%2==0){
  bool ok=false;
  repl(a,1,n){
    ll b=((n+1)^a);
    if(a!=b&&b<n){
      if(a%2==0){
        es.push_back(P(n-1,a-1));
      }else{
        es.push_back(P(n-1,a-1+n));
      }
      if(b%2==0){
        es.push_back(P(n-1+n,b-1));
      }else{
          es.push_back(P(n-1+n,b-1+n));
        }
        ok=true;
        break;
      }
    }
    if(!ok){
    cout<<"No"<<endl;
    return 0;
  }
  }

  cout<<"Yes"<<endl;
  rep(i,es.size())cout<<es[i].fi+1<<" "<<es[i].se+1<<endl;

  return 0;
}
