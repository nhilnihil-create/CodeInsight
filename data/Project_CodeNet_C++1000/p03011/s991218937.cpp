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
  vector<int> a(3);
  rep(i,3) cin>>a[i];
  sort(a.begin(),a.end());
  cout<<a[0]+a[1]<<endl;
return 0;
}