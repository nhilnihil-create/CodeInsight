

#include<bits/stdc++.h>
using namespace std;
int main(){
  long X;cin>>X;
  for(long a=-1000;a<=1000;a++)for(long b=-1000;b<=1000;b++){
    long y=a*a*a*a*a-b*b*b*b*b;
    if(X==y){cout<<a<<" "<<b;return 0;}
  }
}