#include<iostream>
#include<cmath>

using namespace std;

int main(){
  long long a;
  long double b;
  cin>>a>>b;
  cout<<(long long)(a*(__float128)nextafter(b,1e9))<<endl;
}
