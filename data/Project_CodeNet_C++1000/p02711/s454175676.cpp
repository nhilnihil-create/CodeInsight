#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  string a;
  cin>>a;
  ll b=a.size();
  for(ll i=0;i<b;i++){
    if(a.at(i)=='7'){
      cout<<"Yes"<<endl;
      return 0;
    }
    
  }
  cout<<"No"<<endl;
}
