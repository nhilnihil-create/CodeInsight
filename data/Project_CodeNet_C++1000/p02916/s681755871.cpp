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

int a[1000],b[1000],c[1000];
signed main(){
  int n;cin>>n;
  rep(i,n){
    cin>>a[i];a[i]--;
  }
  rep(i,n)cin>>b[i];
  rep(i,n-1)cin>>c[i];
  
  int ans=0;
  rep(i,n){
    ans+=b[i];
    if(i!=0 && a[i-1]+1==a[i])ans+=c[a[i-1]];
  }
  cout<<ans<<endl;
  return 0;
}