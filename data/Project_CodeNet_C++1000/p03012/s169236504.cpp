#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<int> w(n);
  int sum=0;
  for(int i=0;i<n;i++){
    cin>>w[i];
    sum+=w[i];
  }
  int cnt=0,ans=1e9;
  for(int i=0;i<n;i++){
    cnt+=w[i];
    int a=sum-cnt;
    int b=abs(a-cnt);
    ans=min(ans,b);
  }
  cout<<ans<<endl;
}