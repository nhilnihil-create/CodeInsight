#include<bits/stdc++.h>
using namespace std;
int main(){
  
  int n;cin>>n;
  int t = 7%n;
  for(int i=0;i<n+3;i++){
    if(t==0){
      cout<<i+1<<endl;
      return 0;
    }
    t = (t*10+7)%n;
  }
  cout<<-1<<endl;
  return 0;
}
