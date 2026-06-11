#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  string a,c;
  cin>>a>>c;
  ll b=a.size();
  ll d=0;
  for(ll i=0;i<b;i++){
    if(a.at(i)!=c.at(i))d+=1;
  }
  cout<<d<<endl;
}
