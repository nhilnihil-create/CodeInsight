#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int n,i;
  cin >> n;
  vector<pair<ll,ll>> p(n);
  for(i=0;i<n;i++){
    cin >> p.at(i).second >> p.at(i).first;
  }
  
  sort(p.begin(),p.end());
  ll t=0;
  for(i=0;i<n;i++){
    t += p.at(i).second;
    if(t>p.at(i).first){
      cout << "No" << endl;
      return 0;
    }
  }
  
  cout << "Yes" << endl;
}