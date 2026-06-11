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
int keta(int n){
  if(n==0)return 0;
  return keta(n/10)+1;
}
signed main(){
  int n;int ans=0;
  cin>>n;
  rep(i,n+1){
    if(i==0)continue;
    if(keta(i)%2==1)ans++;
  }
  cout<<ans<<endl;
  return 0;
}