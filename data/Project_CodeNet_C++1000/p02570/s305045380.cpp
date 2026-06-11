#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int D, T, S;
  scanf("%d%d%d", &D, &T, &S);
  if (((float)D / (float)S) <= T) 
    printf("Yes");
  else
    printf("No");
  return 0;
}