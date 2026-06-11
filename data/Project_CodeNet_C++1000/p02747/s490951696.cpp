#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

char s[100];
int n;

int main(){
  scanf("%s",s+1);
  n=strlen(s+1);
  if (n&1) {puts("No");return 0;}
  for (int i=1;i<=n;++i)
	if (i&1&&s[i]^'h'||i&1^1&&s[i]^'i') {puts("No");return 0;}
  puts("Yes");
  return 0;
}