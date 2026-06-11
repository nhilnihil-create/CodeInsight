#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

int main(){
  ll n;
  cin>>n;
  ll ans;
  ll cnt=0;
  for(int i=1;i<=sqrt(n);i++){
    if(n%i==0){
      cnt=n/i;
    }
  }
  int i=n/cnt;
  ans=i-1+cnt-1;
  cout<<ans<<endl;
}