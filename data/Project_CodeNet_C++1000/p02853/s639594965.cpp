#include <bits/stdc++.h>
using namespace std;

int main(){
  int X,Y,i;
  cin>>X>>Y;
  i+=(max(4-X,0)*100000+max(4-Y,0)*100000);
  if(X*Y==1)
    i+=400000;
  cout<<i<<endl;
}