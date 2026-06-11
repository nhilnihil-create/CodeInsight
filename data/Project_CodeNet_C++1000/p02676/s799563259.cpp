#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll a,c;
  string b;
  cin>>a>>b;
  c=b.size();
  if(c<=a){
    cout<<b<<endl;
  }
  else{
    string d;
    for(ll i=0;i<a;i++){
      d+=b.at(i);
    }
    d+="...";
    cout<<d<<endl;
  }
}