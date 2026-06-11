#include <bits/stdc++.h>
#include <math.h>
using namespace std;
using ll = long long;
int main() {
  string a,b;
  cin>>a>>b;
  ll c=a.size();
  string d="Yes";
  for(ll i=0;i<c;i++){
    if(a.at(i)!=b.at(i)){
      d="No";
      break;
    }
  }
  cout<<d<<endl;
  
}
