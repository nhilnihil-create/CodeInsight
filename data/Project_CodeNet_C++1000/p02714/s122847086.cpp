#include<bits/stdc++.h>
using namespace std;
int main(){
  long long n,i,k,r=0,g=0,b=0,ans;
  string s;
  cin>>n>>s;
  for(i=0;i<n;i++){
    if(s[i]=='R') r++;
    else if(s[i]=='G') g++;
    else b++;
  }
  ans=r*g*b;
  for(i=0;i<n-2;i++){
    for(k=1;k<(n-i+1)/2;k++){
      if(s[i]!=s[i+k]&&s[i+k*2]!=s[i]&&s[i+k]!=s[i+k*2]) ans--;
    }
  }
  cout<<ans<<endl;
}