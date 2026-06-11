#include <iostream>
using namespace std;

int main(){
  int a;
  int b;
  int c;
  int seged;
  cin >> a;
  cin >> b;
  cin >> c;
  seged=a;
  a=b;
  b=seged;
  seged=c;
  c=a;
  a=seged;
  cout << a<<" "<<b <<" "<<c;
	return 0;
}
