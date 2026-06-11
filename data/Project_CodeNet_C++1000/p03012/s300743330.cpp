#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++) 

using namespace std;

int main() {
  int n;
  cin>>n;
  vector<int> w(n);
  int cnt=0;
  rep(i,n){
    cin>>w[i];
    cnt+=w[i];
  }
  int a=0,ans=1e9;
  for(int i=0;i<n-1;i++){
    a+=w[i];
    ans=min(ans,abs(cnt-a-a));
  }
  cout<<ans<<endl;
}