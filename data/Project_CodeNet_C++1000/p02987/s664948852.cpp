#include <bits/stdc++.h>

using namespace std; 
  
int main()
{
 char s[10];
 scanf("%s", s);
 if(s[0] == s[1] && s[1] != s[2] && s[2] == s[3])printf("Yes\n");
 else if(s[0] == s[2] && s[2] != s[1] && s[1] == s[3])printf("Yes\n");
 else if(s[0] == s[3] && s[3] != s[1] && s[1] == s[2])printf("Yes\n");
 else printf("No\n");
}