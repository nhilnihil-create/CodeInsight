#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll n,i;
  cin >> n;
  vector<ll> a(n),r(n);
  r.at(0)=0;
  for(i=0;i<n;i++){
    cin >> a.at(i);
    if(i%2==0){
      r.at(0) += a.at(i);
    }else{
      r.at(0) -= a.at(i);
    }
  }
  
  cout << r.at(0);
  
  for(i=1;i<n;i++){
    r.at(i)=2*a.at(i-1)-r.at(i-1);
    cout << ' ' << r.at(i);
  }
  cout << endl;
}