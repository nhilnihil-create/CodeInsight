#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<int> a(n);
  double c=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=0;i<n;i++){
    c+=1.0/a[i];
  }
  double ans=1/c;
  cout<<ans<<endl;
}