#include <bits/stdc++.h>
using namespace std;

int main(){
  long x;  cin >> x;
  for(long a=100; a>-200; a--){
    for(long b=a-1; b>=-200; b--){
      if(pow(a, 5)-pow(b, 5) == x){
	cout << a << " " << b << endl;
	return 0;
      }
    }
  }
  return 0;
}
