#include <iostream>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;

int main(){
  int a,b,c,k,count=0;
  cin >> a >> b >> c >> k;
  
  while(a>=b){
    b += b;
    count++;
  }
  while(b>=c){
    c += c;
    count++;
  }
  
  if(count <= k){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
  
  return 0;
}
