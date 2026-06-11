#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll n;
  cin >> n;
  vector<ll> a(n+1),b(n);
  ll i;
  for(i=0;i<n+1;i++){
    cin >> a.at(i);
  }
  for(i=0;i<n;i++){
    cin >> b.at(i);
  }
  
  ll s=0;
  for(i=0;i<n;i++){
    if(a.at(i)>=b.at(i)){
      s += b.at(i);
      a.at(i) -= b.at(i);
      b.at(i)=0;
    }else{
      s += a.at(i);
      b.at(i) -= a.at(i);
      a.at(i)=0;
      if(a.at(i+1)>=b.at(i)){
        s += b.at(i);
        a.at(i+1) -= b.at(i);
        b.at(i)=0;
      }else{
        s += a.at(i+1);
        b.at(i) -= a.at(i+1);
        a.at(i+1)=0;
      }
    }
  }
  cout << s << endl;
}