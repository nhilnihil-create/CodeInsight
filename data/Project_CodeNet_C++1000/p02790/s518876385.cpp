#include<bits/stdc++.h>
using ll=long long;
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  
  if(a>b)swap(a,b);
  int ans=0;
  for(int i=0;i<b;i++){
    ans=ans*10+a;
    
  }
  cout<<ans<<endl;
  return 0;
}
