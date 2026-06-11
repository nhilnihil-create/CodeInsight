#include <bits/stdc++.h>
using namespace std;


int main() {

  long double a,v,b,w,t;
  cin>>a>>v>>b>>w>>t;


  if(w>=v)
    cout<<"NO"<<endl;
  else{
    if(abs(a-b)/(v-w)<=t)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }

    return 0;
}
