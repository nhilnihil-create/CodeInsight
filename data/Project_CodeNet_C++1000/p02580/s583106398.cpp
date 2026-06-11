#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define BITLE(n) (1LL<<((ll)n))
#define SUBS(s,f,t) ((s).substr((f),(t)-(f)))
#define ALL(a) (a).begin(),(a).end()
#define Max(a) (*max_element(ALL(a)))
#define Min(a) (*min_element(ALL(a)))
using namespace std;
ll x[333333],y[333333];
map<pair<ll,ll>,bool>fl;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll h,w,m;
  cin>>h>>w>>m;
  ll mx = 0,my = 0;
  for(int i=0;i<m;i++){
    ll a,b;cin>>a>>b;
    a--;b--;
    fl[mp(a,b)] = true;
    x[a]++;y[b]++;
    mx = max(x[a],mx);
    my = max(y[b],my);
  }
  vector<ll>xx,yy;
  for(int i=0;i<h;i++){
    if(x[i] == mx)
      xx.pb(i);
  }
  for(int i=0;i<w;i++){
    if(y[i] == my)
      yy.pb(i);
  }
  for(int i=0;i<xx.size();i++){
    for(int j=0;j<yy.size();j++){
      if(fl[mp(xx[i],yy[j])] == false){
	cout<<mx+my<<endl;
	return 0;
      }
    }
  }
  cout<<mx+my-1<<endl;
  return 0;
}
