#include<iostream>
using namespace std;

int main(){
  double r;
  const double PI=3.1415926535897932384626;
  cin>>r;
  cout.precision(20);
  cout<<fixed<<PI*r*r<<" "<<2*r*PI<<endl;
  return 0;
}