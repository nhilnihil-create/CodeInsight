#include <stdio.h>

void insertionSort(int *a, int n, int g, int *cnt);

int main(int argc, char const *argv[])
{
  int n,i,a[1000001],cnt=0, m, g[101];

  scanf("%d", &n);
  for(i=0;i<n;i++)
    scanf("%d", a+i);

  g[0] = 1;
  for(i=1;i<100; i++) {
    g[i] = 3*g[i-1] +1;
    if(n< g[i]) {
      m = i;
      break;
    }
  }

  printf("%d\n", m);
  for(i=m-1;i>0;i--)
    printf("%d ", g[i]);
  printf("%d\n", g[i]);

  for(i=m-1;i>=0;i--)
    insertionSort(a,n,g[i], &cnt);

  printf("%d\n", cnt);
  for(i=0;i<n;i++)
    printf("%d\n", a[i]);

  return 0;
}

void insertionSort(int *a, int n, int g, int *cnt)
{
  int i,v,j;
  for(i=g;i<n;i++) {
    v = a[i];
    j = i - g;
    while(j>=0 && a[j] > v) {
      a[j+g] = a[j];
      j = j-g;
      (*cnt)++;
    }
    a[j+g] = v;
  }
}