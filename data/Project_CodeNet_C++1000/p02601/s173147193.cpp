#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int main()
{
  int a,b,c,k;
  cin>>a>>b>>c>>k;
  for(int i=0;i<k;i++){
    if(b<=a)
      b*=2;
    else if(a<b||c<=b)
      c*=2;
    if(a<b&&b<c){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;
}
