#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin>>n;
  vector<pair<long long,long long>> prime;
  for(long long i=2;i*i<=n;i++){
    long long x=0;
    while(n%i==0){
      n/=i;
      x++;
    }
    auto a=make_pair(i,x);
    prime.push_back(a);
  }
  auto a=make_pair(n,1);
  if(n!=1)prime.push_back(a);
  int ans=0;
  for(auto p:prime){
    int x=p.second;
    int y=1;
    while(y<=x){
      x-=y;
      y++;
      ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}