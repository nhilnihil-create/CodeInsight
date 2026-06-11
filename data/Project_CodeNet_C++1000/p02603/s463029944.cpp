#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
  
  int n; cin>>n;
  ll mo = 1000;
  ll ka = 0;
  vector<int> a(n);
  for(auto &i:a) cin>>i;
  for(int i=0; i<n-1; i++){
    if(a.at(i)<=a.at(i+1)){
      ka += mo/a.at(i);
      mo %= a.at(i);
    }
    else{
      mo += ka * a.at(i);
      ka = 0;
    }
  }
  mo += ka * a.at(n-1);
  cout<<mo<<endl;
  
}
