#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll a,b,c,d;
  ll e[4]={};
  cin>>a>>b>>c>>d;
  e[0]=a*c;e[1]=a*d;e[2]=b*c;e[3]=b*d;
  ll p=*max_element(e,e+4);
  cout<<p<<"\n";
    return 0;}
