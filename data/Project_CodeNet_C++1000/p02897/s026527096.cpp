#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  double ans=0;
  if (n%2==0) ans=0.5;
  else ans = (double)(n+1)/(2*n);
  cout << ans;
}