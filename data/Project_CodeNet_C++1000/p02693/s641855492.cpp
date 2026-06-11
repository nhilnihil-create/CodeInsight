#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1LL<<60;
const double EPS = 1e-10;
const ll mod=1000000007;
//const ll mod=998244353;

int main(void){
  ll k,a,b;
  cin>>k>>a>>b;
  for(int i=a;i<=b;i++){
    if(i%k==0){
      cout<<"OK"<<endl;
      return 0;
    }
  }
  cout<<"NG"<<endl;
}