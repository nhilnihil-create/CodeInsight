#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
  ll n;
  cin>>n;
  ll r = n%1000;
  if(r){
    cout<<1000-r<<endl;
  }
  else{
    cout<<0<<endl;
  }
}