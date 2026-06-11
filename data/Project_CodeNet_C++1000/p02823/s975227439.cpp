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
  ll n,a,b;
  cin>>n>>a>>b;
  ll ans;
  if((b-a)%2==0){
    ans=(b-a)/2;
  }
  if((b-a)%2==1){
    if(a-1>=n-b){
      ans=(n-(n-b+1+a))/2+n-b+1;
    }
    if(a-1<n-b){
      ans=(b-a-1)/2+a;
    }
  }
  cout<<ans<<endl;
}