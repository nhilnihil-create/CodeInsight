#include <bits/stdc++.h>
using namespace std;
int main(){
 int K;
  int a[10000001];
 
  cin>>K;
   a[1]=7%K;
  if(a[1]==0){
  cout<<1<<endl;
    return 0;
  }
  else{
  for(int i=2;i<=K;i++){
    a[i]=(a[i-1]*10+7)%K;
    if(a[i]==0){
      
    cout<<i<<endl;
    return 0;
    }
    
  }
  }
  cout<<"-1"<<endl;
  
}
