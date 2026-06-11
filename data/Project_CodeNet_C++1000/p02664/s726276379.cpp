#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=200000;

char s[N+9];
int n;

int main(){
  scanf("%s",s+1);
  n=strlen(s+1);
  for (int i=1;i<=n;++i)
	putchar(s[i]=='?'?'D':s[i]);
  return 0;
}