#include<bits/stdc++.h>
using namespace std;
int main(){
  int count=0,n=0,inp=0;
  cin>>n;
  for(int i=1;i<=n;i++){
  cin>>inp;
    if((i%2 == 1) && (inp%2 == 1)){
    count++;
    }
  }
  cout<<count<<'\n';
  return 0;
}