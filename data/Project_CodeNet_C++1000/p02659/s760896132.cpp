#include<iostream>

using namespace std;

int main(){
  long long a;
  double b;
  cin>>a>>b;
  cout<<(long long)((__float128)a*int(b*100+.5)/100)<<endl;
}
