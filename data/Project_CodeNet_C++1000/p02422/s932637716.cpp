#include <stdio.h>
#include <string.h>

void replace(char *str, int a, int b, char *p);
void reverse(char *str, int a, int b);
void print(char *str, int a, int b);

int main(void)
{
  char str[1001],p[1001],order[10];;
  int a, b, q, i;
  scanf("%s", str);
  scanf("%d", &q);
  for(i=0;i<q;i++) {
    scanf("%s", order);
    if(strcmp(order, "replace") == 0) {
      scanf("%d%d%s", &a, &b, p);
      replace(str, a, b, p);
    } else if (strcmp(order, "reverse") == 0) {
      scanf("%d%d", &a, &b);
      reverse(str,a ,b);
    } else if (strcmp(order, "print") == 0) {
      scanf("%d%d", &a, &b);
      print(str, a, b);
    }
  }
  return 0;
}

void replace(char *str, int a, int b, char *p)
{
  int i;
  for(i=a;i<=b;i++) {
    str[i]=p[i-a];
  }
}

void reverse(char *str, int a, int b)
{
  char temp;
  int i;

  for(i=0;i<=(b-a)/2;i++) {
    temp=str[a+i];
    str[a+i]=str[b-i];
    str[b-i]=temp;
  }
}

void print(char *str, int a, int b)
{
  int i;
  for(i=a;i<=b;i++) {
    putchar(str[i]);
  }
  putchar('\n');
}