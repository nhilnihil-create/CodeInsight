#include<bits/stdc++.h>
using namespace std;
int main()
{
  string j="NG";
  int k,a,b;
  cin>>k>>a>>b;
  for(int c=0; c<=1000; c++){
    if(a<=k*c&&k*c<=b){
      j="OK";
    }
  }
  cout<<j<<endl;
}
