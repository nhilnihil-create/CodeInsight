#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <iostream>
using namespace std;
int main(void)
{

  int n, d, count = 0;
  cin >> n >> d;

  for (int i = n; i > 0; i -= d * 2 + 1)
  {
    count++;
  }
  cout << count << endl;
}
