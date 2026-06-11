#include<bits/stdc++.h>
using namespace std;
char a,b,c;
int main(){
  scanf("%c%c%c",&a,&b,&c);
  if(a=='R'&&b=='R'&&c=='R')puts("3");
  else if(a=='R'&&b=='R')puts("2");
  else if(b=='R'&&c=='R')puts("2");
  else if(a=='R'||b=='R'||c=='R')puts("1");
  else puts("0");
  return 0; 
}