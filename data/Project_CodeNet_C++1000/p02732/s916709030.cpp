#include<bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main(){
  ll n;
  cin>>n;
  vector<ll>a(n);
  map<ll,ll>num;
  for(ll i=0;i<n;i++){
    cin >>a.at(i);
    if(num.count(a.at(i))){
      num.at(a.at(i))++;
    }
    else{num[a.at(i)]=1;}
  }
  ll tmp=0;
  ll tmp2;
  for(auto num1:num){
    tmp2=num1.second*(num1.second-1)/2;
    tmp+=tmp2;
  }
  for(ll i=0;i<n;i++){
    cout <<tmp-(num.at(a.at(i))*(num.at(a.at(i))-1)/2-(num.at(a.at(i))-1)*(num.at(a.at(i))-2)/2)<<endl;
  }
}