#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  	long a, b, c, d, s1, s2, s3, s4;
	cin >> a >> b >> c >> d;
  	s1 = a*c;
  	s2 = a*d;
  	s3 = b*c;
  	s4 = b*d;
  if(s1>=s2 && s1 >=s3 && s1>=s4){
  	cout << s1;
  }else if(s2 >=s3 && s2>=s4){
  	cout << s2;
  }else if(s3>=s4){
  	cout << s3;
  } else {
  	cout << s4;
  }
  
  
  
  return 0;
}
