#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main()
{
  int X;scanf("%d",&X);
  int amari=X%100;
  if(amari>X/100*5)printf("0");
  else printf("1");
}