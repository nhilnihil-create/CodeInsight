#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

int main(){
  int n, m ,k;
  cin >> n >> m >> k;
  vector<int> a(n);
  vector<int> b(m);
  rep(i, n){
    cin >> a[i];
  }
  rep(i, m){
    cin >> b[i];
  }
  int anum=0, bnum=0;
  ll sum=0;
  while(bnum<m && sum+b[bnum]<=k){
    sum+=b[bnum];
    bnum++;
  }
  while(anum<n && sum+a[anum]<=k){
    sum+=a[anum];
    anum++;
  }
  int ans=anum+bnum;
  for(int i=anum; i<n; i++){
    sum+=a[i];
    while(sum > k){
      if(bnum<=0){
        break;
      }
      bnum--;
      sum-=b[bnum];
    }
    if(sum<=k){
      ans=max(ans, i+1+bnum);
    }
  }

  cout << ans << endl;
  return 0;
}
