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
  int n;
  cin>>n;
  vector<int> x(n);
  rep(i,n) cin>>x[i];
  sort(all(x));
  int cnt=0;
  int ans=INF;
  for(int i=x[0];i<=x[n-1];i++){
    cnt=0;
    rep(j,n){
      cnt+=(i-x[j])*(i-x[j]);
    }
    ans=min(ans,cnt);
  }
  cout<<ans<<endl;
}
