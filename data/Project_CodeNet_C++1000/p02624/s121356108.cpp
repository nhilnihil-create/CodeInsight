#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<long long> x(n);
  for(int i=1;i<=n;i++){
    for(int j=i;j<=n;j+=i){
      x[j-1]++;
    }
  }
  long long ans=0;
  for(int i=1;i<=n;i++){
    ans+=i*x[i-1];
  }
  cout<<ans<<endl;
  return 0;
}