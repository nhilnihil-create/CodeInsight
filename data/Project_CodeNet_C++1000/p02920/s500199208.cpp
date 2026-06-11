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

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N;
  cin>>N;
  map<ll,ll> cnt;
  rep(i,1<<N){
    ll s;
    cin>>s;
    cnt[s]++;
  }
  vector<P> ps;
  for(P p : cnt){
    ps.push_back(P(p.fi,p.se));
  }
  sort(all(ps)); reverse(all(ps));
  priority_queue<ll> que;
  que.push(1<<N);
  rep(i,ps.size()){
    ll sz=ps[i].se;
    if(que.size()<sz){
      cout<<"No"<<endl;
      return 0;
    }
    vector<ll> st;
    while(sz>0){
      ll v=que.top(); que.pop();
      for(ll j=1;j<v;j<<=1)st.push_back(j);
      sz--;
    }
    rep(j,st.size())que.push(st[j]);
  }
  cout<<"Yes"<<endl;

  return 0;
}
