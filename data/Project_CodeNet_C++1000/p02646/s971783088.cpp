#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll A,V,B,W,T;
  cin>>A>>V>>B>>W>>T;
  if((V-W)*T>=max(B-A,A-B)){cout<<"YES"<<endl;}
  else{cout<<"NO"<<endl;}
}
