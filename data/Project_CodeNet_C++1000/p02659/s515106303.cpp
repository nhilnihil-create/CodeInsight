#include <iostream>
#include <boost/multiprecision/cpp_dec_float.hpp>
using namespace std;

int main(){
  boost::multiprecision::cpp_dec_float_50 a, b;
  cin >> a >> b;
  cout << llround(floor(a * b)) << endl;
}