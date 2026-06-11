#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll a,b,c;
  cin>>a>>b>>c;
  if(a==b&&b==c){
    cout<<"No"<<endl;
    return 0;
  }
 if(a!=b&&b!=c&&a!=c){
   cout<<"No"<<endl;
   return 0;
 }
  cout<<"Yes"<<endl;
} 
