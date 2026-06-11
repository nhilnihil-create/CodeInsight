#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int m=998244353;
int main(){
  int n;
  cin >> n;
  vector<int> a(n),b(n);
  rep(i,n) cin >> a[i];
  b[0]=1;
  if(a[0]!=0){
    cout << 0 << "\n";
    return 0;
  }
  sort(a.begin(),a.end());
  if(a[1]!=1){
    cout << 0 << "\n";
    return 0;
  }
  int i=1; ll ans=1;
  while(i<n){
    ans*=b[a[i]-1];
    ans%=m;
    b[a[i]]++;
    i++;
  }
  cout << ans << "\n";
  return 0;
}