#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; } template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define M 1000000007
#define all(a) (a).begin(),(a).end()
#define rep(i,n) reps(i,0,n)
#define reps(i,m,n) for(int i=(m);i<(n);i++)
int main(){
  ll n;cin>>n;
  vector<ll> a(n);
  rep(i,n)cin>>a[i];
  sort(all(a));
  vector<P> p;
  reps(i,1,n-1){
    if(a[i]<0){
      p.push_back(P(a[n-1],a[i]));
      a[n-1]-=a[i];
    }else{
      p.push_back(P(a[0],a[i]));
      a[0]-=a[i];
    }
  }
  p.push_back(P(a[n-1],a[0]));
  cout<<a[n-1]-a[0]<<endl;
  rep(i,n-1){
    cout<<p[i].first<<" "<<p[i].second <<endl;
  }
}