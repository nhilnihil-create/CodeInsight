#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;

int main(){
  long long int t,tt,a,aa,b,bb;
  cin >> t >> tt;
  cin >> a >> aa;
  cin >> b >> bb;
  if((t*a+tt*aa) == (t*b+tt*bb)){
  	cout << "infinity" << endl; return 0;
  }
  if((t*a+tt*aa)<(t*b+tt*bb)){
  	swap(a,b); swap(aa,bb);
  }
  if(a>b){cout << 0 << endl; return 0;}
  long long int d = (t*a+tt*aa) - (t*b+tt*bb);
  cout << 2*((t*(b-a))/d) + 1 - ((t*(b-a))%d ==0 ? 1 : 0)<< endl;
  return 0;
}
