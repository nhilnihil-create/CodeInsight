#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,wa=0,i;
  cin>>a>>b;
  int n[b];
  for(i=0;i<b;i++){
    cin>>n[i];
    wa+=n[i];
  }
  a-=wa;
  if(a<0){
    cout<<-1;
  }else{
    cout<<a;
  }
}
