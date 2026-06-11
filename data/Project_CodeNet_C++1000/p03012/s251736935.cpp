#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int su=0;
  vector<int>omoi(n);
  for(int i=0;i<n;i++){
    cin >> omoi.at(i);
    su+=omoi.at(i);
  }
  int ans=10e4,a=0,b=su;
  for(int i=0;i<n;i++){
    a+=omoi.at(i);
    b-=omoi.at(i);
    ans=min(ans,abs(a-b));
  }
  cout << ans << endl;
  return 0;
}