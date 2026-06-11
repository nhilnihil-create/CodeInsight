#include <iostream>
using namespace std;

int main() {
  int dan;
  while (cin >> dan && dan>0) {
    int array[dan];
    for (int i=0;i<=dan;++i) {
      if (i==0)
	array[i] = 1;
      else if (i==1)
	array[i] = array[i-1];
      else if (i==2)
	array[i] = array[i-1]+array[i-2];
      else
	array[i] = array[i-1]+array[i-2]+array[i-3];
    }
    cout << (((array[dan]+9)/10)+364)/365 << endl;
  }
}