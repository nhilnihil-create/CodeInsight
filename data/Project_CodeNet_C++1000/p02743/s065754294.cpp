#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long a,b,c,d,e;
  cin>>a>>b>>c;
  if((c-a-b)<0){
    cout<<"No"<<endl;
  }
  else{
  d=4*a*b;
  e=(c-a-b)*(c-a-b);
    if(d<e){
      cout<<"Yes"<<endl;
    }
    else{
      cout<<"No"<<endl;
    }
  }
}