#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  string s;
  cin>>s;
  int ans=0;
  for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
      if(s[i]!=s[j]){
        i=j-1;
        break;
      }else{
        i=j;
      }
    }
    ans++;
  }
  cout<<ans<<endl;
  return 0;
}