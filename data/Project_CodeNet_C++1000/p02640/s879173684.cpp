#include <iostream>
using namespace std;
int main(){
  int X,Y;
  cin >> X >> Y;
  bool ans= false;
  for(int i=0; i<=X; i++){
    if(4*X-2*i==Y){
      ans = true;
      break;
    }
  }
  if(ans){
    cout << "Yes" << endl;
  }
    else{
      cout<< "No" << endl;
    }
}

    
    
