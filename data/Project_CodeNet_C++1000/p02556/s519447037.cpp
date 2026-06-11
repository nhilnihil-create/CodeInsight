#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> x(n);
  vector<int> y(n);
  for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    x[i] = a+b;
    y[i] = a-b;
  }
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());

  int ans = max(abs(x[n-1]-x[0]),abs(y[n-1]-y[0]));
  cout<<ans<<endl;
  return 0;
}

