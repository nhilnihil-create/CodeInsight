#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,ans=0,cnt=0;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++)cin >> a[i];
  for(int i=0;i<n-1;i++){
    if(a[i]>=a[i+1])cnt++;
    else{
      ans=max(ans,cnt);
      cnt=0;
    }
  }  
  ans=max(ans,cnt);
  cout << ans << endl;
}
