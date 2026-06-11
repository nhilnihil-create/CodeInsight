#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string n; cin>>n;
  string a="Sunny",b="Cloudy",c="Rainy";
  if(n==a)cout<<b<<endl;
  if(n==b)cout<<c<<endl;
  if(n==c)cout<<a<<endl;
}