#include <iostream>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;

int main(){
  long a,v,b,w,t;
  cin >> a >> v >> b >> w >> t;
  
  if(a<b){
    if((b-a) <= (v-w)*t){
      cout << "YES";
    }
    else{cout << "NO";}
  }
  else if(a>b){
    if((a-b) <= (v-w)*t){
      cout << "YES";
    }
    else{cout << "NO";}
  }
  
  return 0;
}
