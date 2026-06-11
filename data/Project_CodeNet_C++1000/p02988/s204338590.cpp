#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
  int n,ans=0;
  cin >> n;
  int p[n];
  rep(i,n)
    cin >> p[i];
  for(int i = 1;i<n-1;i++){
    if(min(p[i-1],min(p[i],p[i+1]))!=p[i] && max(p[i-1],max(p[i],p[i+1])) != p[i])
      ans++;
  }
  cout << ans << endl;
}