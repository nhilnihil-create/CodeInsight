#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int>b(n-1);
  for(int i=0;i<n-1;i++)
    cin >> b.at(i);
  reverse(b.begin(),b.end());
  int a=1e5,ans=0;
  for(int i=0;i<n-1;i++){
    ans+=min(a,b.at(i));
    a=b.at(i);
  }
  ans+=a;
  cout << ans << endl;
  return 0;
}