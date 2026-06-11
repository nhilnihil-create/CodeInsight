#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,x,n) for(int i=x;i<n;i++)
#define pb push_back
#define MAX 100005
#define int long long
using namespace std;
const int MOD=1000000007;
const int INF=1000000009;


vector<int> LIS(const vector<int> &a){
  vector<int> dp(a.size(),INF);
  rep(i,a.size()){
    *lower_bound(dp.begin(),dp.end(),a[i])=a[i];
  }
  return vector<int>(dp.begin(),lower_bound(dp.begin(),dp.end(),INF));
}


signed main(){
  int n;
  cin>>n;
  vector<int> a(n);
  rep(i,n)cin>>a[i];

  vector<int> b=LIS(a);
  cout<<b.size()<<endl;

  return 0;
}