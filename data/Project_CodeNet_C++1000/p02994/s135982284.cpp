#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int a, b;
  cin >> a >> b;
  int sum = b;
  int s = 0, t = abs(b); 
  for(int i=1; i<a; i++) { 
	if( t > abs(b + i) ){ s = i; t = abs(b + i); }
    sum += (b + i);
  }
  cout << (sum - (b + s)) << endl;
  return 0;
}