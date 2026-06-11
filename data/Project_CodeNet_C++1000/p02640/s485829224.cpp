#include<iostream>
using namespace std;
int main(){
  int x,y;
  cin >> x >> y;
  if(y%2!=0){
    cout << "No" << endl;
  }
  else if(x*2>y || x*4<y){
    cout << "No" << endl;
  }
  else{
    cout << "Yes" << endl;
  }
  return 0;
}
