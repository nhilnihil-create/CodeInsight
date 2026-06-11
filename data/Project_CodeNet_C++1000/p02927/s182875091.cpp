#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
typedef pair<int,int> P;

const int MOD=1000000007;
int INF=100100100100100;

signed main(){
  int m,d;cin>>m>>d;
  int ans=0;
  rep(i,m+1){
    rep(j,d+1){
      int a=j/10,b=j%10;
      if(a<2 || b<2)continue;
      if(i==a*b)ans++;
    }
  }
  cout<<ans<<endl;
      
  return 0;
}