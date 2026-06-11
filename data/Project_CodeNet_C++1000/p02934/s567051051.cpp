#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<int> a(n);
  double d=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    d+=1.0/a[i];
  }
  double ans=1.0/d;
  cout<<ans<<endl;
}