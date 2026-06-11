#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t n;
  cin >> n;
  int64_t a=100,c=0;
//  const long double x=1.01;
  while(a<n){
    c++;
    a+=a/100;
  }
  cout << c << endl;
  return 0;
}