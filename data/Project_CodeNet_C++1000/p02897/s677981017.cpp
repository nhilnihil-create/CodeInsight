#include <iostream>
 
using namespace std;
 
int main(){
  int n; cin >> n;
  if(n%2==0) cout << 0.5 << endl;
  else {
    cout << ((n+1)/2)/(double)(2*(n/2)+1) << endl;
  }
}