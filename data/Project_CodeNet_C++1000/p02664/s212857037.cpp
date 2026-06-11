#include <stdio.h>
#include <cstring>
char s[200050];
int main()
{
  scanf("%s",s);
  int len=strlen(s);
  for(int i=0;i<len;++i)
    if(s[i]=='?')
      s[i]='D';
  printf("%s\n",s);
  return 0;
}