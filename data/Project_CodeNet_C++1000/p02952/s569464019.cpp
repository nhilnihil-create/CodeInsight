#include<bits/stdc++.h>
using namespace std;
int f(int x){
  int keta=0;
  while(x!=0){
    x/=10;
    keta++;
  }
    return keta;
}
int main(){
  int N;
  cin>>N;
  int ans=0;
  for(int i=1;i<=N;i++){
    if(f(i)%2==1){
      ans++;
    }
  }
  cout<<ans<<endl;
}
