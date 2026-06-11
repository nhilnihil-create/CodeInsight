#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,ans=(1<<10);
  cin >> n;
  int w[n];
  for(int i=0;i<n;i++)cin >> w[i];
  for(int i=0;i<n;i++){
    int s=0,s1=0;
    for(int j=0;j<n;j++){
      if(i>=j)s1+=w[j];
      else s+=w[j];
    }
    ans=min(ans,abs(s1-s));
  }
  cout << ans << endl;
}