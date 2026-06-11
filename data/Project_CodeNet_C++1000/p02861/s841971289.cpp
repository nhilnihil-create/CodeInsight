#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a;
  cin>>a;
  vector<vector<ll>>vec(a,vector<ll>(2));
  for(ll i=0;i<a;i++){
    cin>>vec.at(i).at(0)>>vec.at(i).at(1);
  }
  double b=0;
  for(ll i=1;i<a;i++){
    for(ll j=0;j<i;j++){
      double c=(vec.at(i).at(0)-vec.at(j).at(0))*(vec.at(i).at(0)-vec.at(j).at(0))+(vec.at(i).at(1)-vec.at(j).at(1))*(vec.at(i).at(1)-vec.at(j).at(1));
      b+=sqrt(c);
    }
  }
  
  cout<<setprecision(11);
  cout<<b*2/a<<endl;
  
  
      
                        
                        
}
