#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
int main(){
  long long a,b,c;
  cin>>a>>b>>c;
  long long x=c-a-b;
  if(x>0&&4*a*b<x*x) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  
  return 0;
}