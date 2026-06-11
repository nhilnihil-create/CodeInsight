#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a;
  cin>>a;
  vector<ll>vec(a);
  ll b=0;
  for(ll i=0;i<a;i++){
    cin>>vec.at(i);
  }
  for(ll i=0;i<a-2;i++){
    if((vec.at(i+1)<vec.at(i)&&vec.at(i+2)<vec.at(i+1))||(vec.at(i+1)>vec.at(i)&&vec.at(i+2)>vec.at(i+1))){
      b+=1;
    }
  }
  cout<<b<<endl;
}