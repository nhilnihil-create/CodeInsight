# include <iostream>
using namespace std;
int main(){
  int a,b,c;
  cin >> a >> b >> c;
  int d = a-b;
  int e = c-d;
  if ( e>0){
  cout << e;
  }
  else{
    cout << "0";
  }
  return 0;
}
