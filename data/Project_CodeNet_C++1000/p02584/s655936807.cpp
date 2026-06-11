#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll a,b,c;
  cin >>a>>b>>c;
  ll cnt=abs(a)/c;
  ll ans;
  if(a<=0){
    a+=cnt*c;
    if((b-cnt)%2==0){
      ans=abs(a);
    }
    else{
      ans=abs(a+c);
    }
    if(cnt>b){
      ans=abs(a-(cnt-b)*c);
    }
  }
  else{
    a-=cnt*c;
    if((b-cnt)%2==0){
      ans=abs(a);
    }
    else{
      ans=abs(a-c);
    }
    if(cnt>b){
      ans=abs(a+(cnt-b)*c);
    }
  }
  
  cout << ans <<endl;
}
