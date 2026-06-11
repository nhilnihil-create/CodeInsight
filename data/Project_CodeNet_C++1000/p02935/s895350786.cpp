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
  int n;cin>>n;
  long double a[100],ans=0;
  rep(i,n)cin>>a[i];
  sort(a,a+n,greater<long double>());
  
  rep(i,n){
    int k=i+1;
    if(i==n-1)k=n-1;
    rep(j,k){
      a[i]=a[i]/2;
    }
    ans+=a[i];
  }
  cout<<setprecision(15)<<ans<<endl;
  return 0;
}