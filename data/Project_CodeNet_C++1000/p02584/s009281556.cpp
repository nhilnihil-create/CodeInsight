// 2020/08/23
// Walking Takahashi

#include <iostream>
#include <fstream>
#include <math.h>
#include <string>

using namespace std;

int main(){

  long long x, k, d;
  cin >> x >> k >> d;

  long long quo; // quotient
  quo = abs(x) / d;
  //cout << "quo=" << quo << endl;

  long long ans, tmp1, tmp2;
  if(k<=quo){
    ans = abs(x) - k*d;
  } else {
    if((k-quo)%2==0){
      ans = abs(abs(x) - quo*d);
      //cout << "0" << endl;
    } else{
      ans = abs(abs(x) - (quo+1)*d);
      //cout << "1" << endl;
    }
  }

  cout << ans;
}

