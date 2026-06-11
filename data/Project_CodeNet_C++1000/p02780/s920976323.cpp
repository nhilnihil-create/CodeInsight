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
  int n,k;cin>>n>>k;
  int a[200010];
  rep(i,n)cin>>a[i],a[i]++;
  int MA=0,sum=0;
  rep(i,k)sum+=a[i];
  MA=sum;
  for(int i=k;i<n;i++){
    sum+=a[i]-a[i-k];
    //cout<<sum<<endl;
    MA=max(MA,sum);
  }
  if(MA%2==0)cout<<MA/2<<endl;
  else cout<<MA/2<<'.'<<5<<endl;
  return 0;
}
