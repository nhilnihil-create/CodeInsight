#include <iostream>
#include <cstdio>
using namespace std;

void cal(int a, int b){

  double f = (double)a/(double)b;
  printf("%d %d %.5f\n", a/b, a%b, f);

}

int main(){
  int a, b;

  cin >> a >> b;
  cal(a,b);
}