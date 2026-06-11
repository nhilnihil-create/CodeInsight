#include <iostream>
#define rep(i,n) for(int i=1; i<(n); i++)
using namespace std;

int main(){
  int x,count=0;
  cin >> x;
  
  rep(i,400){
    if((x*i) % 360 == 0){
      count = i;
      break;
    }
  }
  
  cout << count << endl;
  
  return 0;
}
