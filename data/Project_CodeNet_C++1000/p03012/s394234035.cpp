#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)
#define REP(i,m,n) for(ll i=(ll)(m); i<(ll)(n); ++i)
#define F first
#define S second
const double PI=acos(-1);
//fixed<<setprecision(11)<<

int main(){
  int n;cin>>n;
  int tmp1=0,tmp2=0;
  int ans;
  vector<int> w(n);
  rep(i,n){
    cin>>w[i];
    tmp1+=w[i];
  }

  vector<int> T;
  rep(i,n){
    tmp1-=w[i];
    tmp2+=w[i];
    T.push_back(abs(tmp1-tmp2));
  }
  sort(T.begin(),T.end());
  ans=T[0];
  cout<<ans<<endl;
return 0;
}