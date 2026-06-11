#include <bits/stdc++.h>
using namespace std;

int f(int n,int k){
  return (n&k)==k;
}

signed main(){
  int n;cin>>n;
  string s;cin>>s;
  int a=2;
  for(int i=0;i<n;i++)if(s[i]=='2')a=1;
  for(int i=0;i<n;i++){
    if(a==1&&s[i]=='3')s[i]='1';
    if(a==2&&s[i]=='3')s[i]='2';
  }
  int od=0;
  for(int i=0;i<n;i++){
    if(s[i]=='2'){
      od^=f(n-1,i);
    }
  }
  cout<<od*a<<endl;
}
