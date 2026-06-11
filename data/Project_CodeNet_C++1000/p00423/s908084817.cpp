#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  int c1,c2,p1 = 0,p2 = 0;
  while(scanf("%d",&n)){
    if(n == 0)break;
    p1 = p2 = 0;
    while(n--){
      scanf("%d %d",&c1,&c2);
      if(c1 > c2)p1 += c1+c2;
      else if(c1 < c2)p2 += c1+c2;
      else{
	p1 += c1;
	p2 += c2;
      }
    }
    printf("%d %d\n",p1,p2);
  }
}