#include<bits/stdc++.h>
using namespace std;
const unsigned int M = 1000000007;
int main(){
 long long x,k,d;
 cin >> x >> k >> d;
  x = abs(x);
  long long straight = min(k,x/d);
  k -= straight;
  x -= straight*d;
  if(k%2==0){
     cout << x << endl;
  }else{
     cout << d-x << endl;
  }
  return 0;
}