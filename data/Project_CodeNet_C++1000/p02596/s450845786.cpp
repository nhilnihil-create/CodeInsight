#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll k;
  cin>>k;
  ll cul=0,i;
  for(i=1;i<k+1;i++){
  	cul*=10;
    cul+=7;
    cul%=k;
    if(cul==0){
      	cout<<i<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
  return 0;
}

