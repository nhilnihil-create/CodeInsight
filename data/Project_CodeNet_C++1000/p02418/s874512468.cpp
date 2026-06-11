#include<stdio.h>

int judge(char s[], char p[]) {
  int sn = 0, pn = 0, flag = 0, i, j, k, temp, pi, hantei = 0, breakflag = 0;
  while (flag == 0)
  {
    if (s[sn] >= 97 && s[sn] <= 122)
    {
      sn++;
    }
    else
    {
      flag = 1;
    }
  }
  
  flag = 0;
  
  while (flag == 0)
  {
    if (p[pn] >= 97 && p[pn] <= 122)
    {
      pn++;
    }
    else
    {
      flag = 1;
    }
  }
  
  for (i = 0; i < sn; i++)
  {
    pi = 0;
    for (k = 0; k < pn; k++)
    {
      if (s[k] == p[k])
      {
        pi++;
      }
      
      if (pi == pn)
      {
        return hantei = 1;
      }
    }
    
    temp = s[sn - 1];
    for (j = sn - 2; j >= 0; j--)
    {
      s[j + 1] = s[j];
    }
    s[0] = temp;
  }
  
  if (hantei == 1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int main(void) {
  char s[100], p[100], i;
  scanf("%s", s);
  scanf("%s", p);
  
  if (judge(s, p) == 1)
  {
    printf("Yes\n");
  }
  else
  {
    printf("No\n");
  }
  
  return 0;
}