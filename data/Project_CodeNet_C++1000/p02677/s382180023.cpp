#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
int main(){
  ld s,h,H,M;
  cin>>s>>h>>H>>M;
  ld tmp=(M/60)*360;
  ld tmp2=tmp/12+(H/12)*360;
  //cout<<tmp2<<endl;
  if(tmp==0)tmp=360;
  ld teta=(abs(tmp-tmp2)/180)*M_PI;
  //cout<<teta<<endl;
  ld c=s*s+h*h-2*s*h*cos(teta);
  cout<<fixed<<setprecision(10)<<sqrt(c)<<endl;
}