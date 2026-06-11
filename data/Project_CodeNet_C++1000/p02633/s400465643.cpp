#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
#define rep(i,n) for(ll i=0;i<n;i++)

int main(){
  int x;cin>>x;
  for(int i=1;i<10000000;i++){
    if((x*i)%360==0){
      cout<<i<<endl;
      break;
    }
  }
  return 0;
}