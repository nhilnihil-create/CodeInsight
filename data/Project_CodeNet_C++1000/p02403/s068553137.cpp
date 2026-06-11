#include <cstdio>
#include <math.h>
#include <utility>

using namespace std;

int main ()
{
  int H, W;
  int count = 0;
  pair<int, int> data[5000];

  while (1) {
    scanf("%d", &H);
    scanf("%d", &W);
    if (H == 0 && W == 0) {
      break;
    }
    data[count].first = H;
    data[count].second = W;
    count++;

  }

  for (int i = 0; i < count; i ++) {
    for (int j = 0; j < data[i].first; j++) {
      for (int k = 0; k < data[i].second; k++) {
        printf("#");
      }
      printf("\n");
    }
    printf("\n");
  }

  return 0;
}