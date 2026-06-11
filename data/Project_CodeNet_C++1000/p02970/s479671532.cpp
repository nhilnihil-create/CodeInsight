#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,d;
  cin>>n>>d;
  int ans=0;
  int count=0;
  while(count<n){
    ans++;
    count+=1+2*d;
  }
  cout<<ans<<endl;
}
