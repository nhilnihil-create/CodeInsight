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

ll N;
vector<ll> A,B;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin>>N;
  A.resize(N);
  B.resize(N);
  rep(i,N)cin>>A[i];
  rep(i,N)cin>>B[i];

  priority_queue<P> que;
  rep(i,N)que.push(P(B[i],i));
  ll res=0;
  while(que.size()){
    //rep(j,N)cout<<B[j]<<" ";
    //cout<<endl;
    P p=que.top(); que.pop();
    ll i=p.se;
    ll a=B[(i-1+N)%N],b=p.fi,c=B[(i+1+N)%N];
    ll op=A[i];
    if(b<op){
      cout<<-1<<endl;
      return 0;
    }
    ll x=(b-op)/(a+c);
    B[i]-=x*(a+c);
    res+=x;
    if(x==0&&A[i]!=B[i]){
      cout<<-1<<endl;
      return 0;
    }
    if(B[i]>A[i]){
      que.push(P(B[i],i));
    }
  }

  rep(i,N)if(A[i]!=B[i]){
    cout<<-1<<endl;
    return 0;
  }
  cout<<res<<endl;

  return 0;
}
