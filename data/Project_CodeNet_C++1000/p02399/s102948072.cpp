#include <iostream>
#include <iomanip>
using namespace std;
int main(){
  long int a,b;
  double c,d;
  cin>>a>>b;
  c=a;
  d=b;
  cout<<a/b<<" "<<a%b<<" "<<fixed<<setprecision(5)<<c/d<<endl;
  return 0;
}