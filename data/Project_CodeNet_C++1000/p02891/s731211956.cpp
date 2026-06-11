#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
  string str;
  cin>>str;
  ll K;
  cin>>K;
  ll memo=str.size();
  ll x=1,checker=0;
  if(str.at(0)==str.at(memo-1)){checker=54;}
  if(memo==1){
    cout<<K/2<<endl;return 0;
  }
  while(true){
    if(str.at(x)!=str.at(x-1))break;
    if(x==str.size()-1){cout<<(ll)str.size()*K/2<<endl;return 0;}
    x++;
  }
  ll rock=1;
  for(ll i=(ll)str.size()-1;i>=0;i--){
    if(str.at(i)==str.at(i-1)){rock++;}
    else{break;}
  }
  ll ans3=rock/2;
  rock=1;
  for(ll i=0;i<=(ll)str.size()-1;i++){
    if(str.at(i)==str.at(i+1)){rock++;}
    else{break;}
  }
  ll ans4=rock/2;
  ll ans1=0,ans2=0;
  str=str+str.at(0);
  ll k=0;
  //cout<<str<<endl;
  while(str.at(k+1)==str.at(k)){
    //cout<<k<<" "<<str.at(k+1)<<" "<<str.at(k)<<endl;
    str=str+str.at(1+k);
    //cout<<str<<endl;
    k++;
    if(1+k>=memo)break;
  }
  //cout<<str<<endl;
  for(ll i=1;i<(ll)str.size();i++){
    ll j=0;
    ll count;
    count=1;
    while(str.at(i+j)==str.at(i-1+j)){
      //cout<<i+j<<" "<<i-1+j<<endl;
      count++;j++;
      if(i+j>=str.size()){break;}
    }
    //cout<<i<<" "<<i+j-1<<" "<<count<<endl;
    if(i+j>=memo){ans2+=(count/2);break;}
    else{ans1+=(count/2);}
    i+=max(0,(int)j-1);
  }
  //ans1は右側を除いた連続部分　ans2は右側の連続成分
  //ans3は連結する前の右側の連続成分　ans4は左側の連続成分
  //cout<<ans1<<" "<<ans2<<" "<<ans3<<" "<<ans4<<endl;
  if(checker==54){cout<<(ans1-ans4)*K+ans2*(K-1)+ans3+ans4<<endl;}
  else{cout<<K*(ans1+ans3)<<endl;}
  //cout<<checker<<endl;
}