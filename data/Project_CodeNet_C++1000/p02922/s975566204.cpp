#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  int ans=0,count=1;
  while(count<b){
    count+=a-1;
    ans++;
  }
  cout<<ans<<endl;
}
  
