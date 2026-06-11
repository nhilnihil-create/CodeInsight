#include <iostream>
using namespace std;

int main()
{
  int a,b,c,d,e,f,i;
  for(int i=1; i>0;){
    cin >> a >> b;
    if(a == 0 && b == 0){
      break;
    }
    for(int ii=0; ii<a; ii++){
      for(int iii=0; iii<b; iii++){
	cout << "#";
      }
      cout << endl;
    }
    cout << endl;
  }
}