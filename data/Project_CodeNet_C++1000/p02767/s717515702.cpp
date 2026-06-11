#include <bits/stdc++.h>
using namespace std;
const int INF=100000000;
int main(){
  int n;
  cin>>n;
  vector<int> x(n);
  for(int i=0;i<n;i++)cin>>x[i];
  
  long long ans=INF;
  for(int p=1;p<=100;p++){
    long long res=0;
    for(int i=0;i<n;i++){
      int a=x[i]-p;
      res+=a*a;
    }
    ans=min(ans,res);
  }
  cout<<ans<<endl;
  return 0;
}
  