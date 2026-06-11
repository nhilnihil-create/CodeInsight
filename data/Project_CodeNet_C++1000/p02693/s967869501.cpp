#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a,b,c,e;
  cin>>a>>b>>c;
  e=c%a;
  if(c-b>=e){
    cout<<"OK"<<endl;
  }
  else{
    cout<<"NG"<<endl;
  }
  
}
