#include <iostream>
using namespace std;

int main()
{

  int a,b,c,d = 0;
  for(int i=1; i>0;){
    cin >> a >> b;
    if(a == 0 && b == 0){
      break;
    }
    else{
    if(a < b){
      cout << a << " " << b << endl;
    }
    else{
      cout << b << " " << a << endl;
    }
    }
  }
}
      