#include <iostream>
using namespace std;

int main() {
  int a,b;
  cin >> a >> b;
  a-b*2;
  if (a-b*2<0) {
    cout << 0;
  }else{
    cout << a-b*2;
  }
	return 0;
}
