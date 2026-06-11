#include <iostream>
using namespace std;
#define max(a,b) ((a)>(b) ? (a) : (b))
int main(){
  int i,k,x;
  cin >> k >> x;
  for(i=x-k+1;i<=x+k-1;i++){
    cout << i << (i==x+k-1 ? '\n' : ' ');
  }
  return 0;
}