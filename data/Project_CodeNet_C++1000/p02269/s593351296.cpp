#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 10000000 + 5;
char s[20] , od[12];
bool hash[maxn];

int get(char c) {
  switch(c) {
     case 'A': return 1;
     case 'C': return 2;
     case 'G': return 3;
     case 'T': return 4;
  }
}

int h(char s[]) {
   int len = strlen(s);
   int k = 0;
   for(int i = 0 ; i < len ; i++) {
      k = k * 5 + get(s[i]);
   }
   return k;
}

int main()
{
  int n;
  scanf("%d",&n);
  for(int i = 1 ; i <= n ; i++) {
     scanf("%s%s",od , s);
     if(od[0] == 'i') hash[h(s)] = 1;
     if(od[0] == 'f') {
        if(hash[h(s)]) printf("yes\n");
        else printf("no\n");
     }
  }
  return 0;
}
