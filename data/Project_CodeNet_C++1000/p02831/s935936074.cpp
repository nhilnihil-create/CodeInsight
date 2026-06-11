#include<iostream>
using namespace std;
int gcd(long a,long b){
if(a==0)
    return b;
    return gcd(b%a,a);
}
int main(){
  long long x,y,z;
  cin>>x>>y;
  if(x>y)
    swap(x,y);
  z=((x*y)/gcd(x,y));
  cout<<z;
}
