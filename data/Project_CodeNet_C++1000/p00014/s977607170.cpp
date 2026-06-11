#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  int in;
  while(cin>>in){
    int number = 600/in;
    int sum = 0;
    for(int i=1; i<number; i++){
      sum += pow(i*in, 2) * in;
    }
    cout << sum << endl;
  }
  return 0;
}