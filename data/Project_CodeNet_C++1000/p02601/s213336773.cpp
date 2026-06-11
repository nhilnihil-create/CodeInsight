#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,d,e=0;
  cin>>a>>b>>c>>d;
  while(e<d){
    if(a>=b)b=b*2;
    else if(b>=c)c=c*2;
    e++;
  }
  if(a<b&&b<c)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}