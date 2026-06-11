#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t a,b,c,d,e,f;
  cin>>a>>b>>c>>d>>e>>f;
  int64_t i=a*(c-e);
  int64_t j=b*(d-f);
  if(i+j==0){
    cout<<"infinity"<<endl;
  }
  else if(i>0 && j>=0){
    cout<<0<<endl;
  }
  else if(i<0 && j<=0){
    cout<<0<<endl;
  }
  else{
    if(i>0){
      i=-i;
      j=-j;
    }
    if(i+j<0){
      cout<<0<<endl;
    }
    else{
      if((-i)%(i+j)!=0){
        cout<<((-i)/(i+j))*2+1<<endl;
      }
      else{
        cout<<((-i)/(i+j))*2<<endl;
      }
    }
  }
}