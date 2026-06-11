#include<iostream>
#include<cstdio>
using namespace std;
int main() {
  int a,b; scanf("%d%d",&a,&b); int cnt = 0;
  for(int x=2;x<=9;x++)
    for(int y=2;y<=9;y++) if(x * y <= a && x * 10 + y <= b) cnt++; printf("%d",cnt);
}
