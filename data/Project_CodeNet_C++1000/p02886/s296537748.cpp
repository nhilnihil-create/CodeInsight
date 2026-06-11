#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i<(n);i++)
#define fore(i,a) for(auto &i:a)
#define debug(a,b) cout << "debug : " << a << " , "<< b << endl
using ll=long long;
const ll INF=1LL<<60;
const ll mod=1E9+7;


int main(){
  int n;
  cin >> n;
  vector<int>a(n);
  rep(i,n)cin >> a[i];
  int sum=0;
  rep(i,n){
    rep(j,n){
      if(i!=j)sum+=a[i]*a[j];
    }
  }
  cout << sum/2;
}
