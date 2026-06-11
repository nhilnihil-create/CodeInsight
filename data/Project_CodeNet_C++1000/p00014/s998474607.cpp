#include <iostream>
#include <cstdio>

using namespace std;

int main() {
  int d, sum;
  while(!feof(stdin)) {
    scanf("%d", &d);
    if(feof(stdin)) break;
    sum=0;
    for(int i=d;i!=600;i+=d) {
      //printf("%d\n", i*i*i*d);
      sum+=d*i*i;
    }
    printf("%d\n", sum);
  }
}