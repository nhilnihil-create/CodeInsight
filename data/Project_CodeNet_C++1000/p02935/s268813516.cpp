#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  double ans=0.0;
  cin >> n;
  double v[n];
  for(int i=0;i<n;i++)cin >> v[i];
  sort(v,v+n);
  for(int i=0;i<n;i++){
    if(i==n-1)ans=v[n-1];
    else v[i+1]=(v[i]+v[i+1])/2;
  }
  cout << ans << endl;
}