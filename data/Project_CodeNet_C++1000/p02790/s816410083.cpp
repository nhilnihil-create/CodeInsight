#include <iostream>
using namespace std;

int main() {
	int a,b;
  scanf("%d%d",&a,&b);
        int x=b,y=a,a1=a,b1=b;
  while(x!=1)
        {
          a=a*10+a1;
          --x;
        }
         while(y!=1)
        {
          b=b*10+b1;
          --y;
        }
        int m=max(a,b);
        printf("%d",m);
	return 0;
}
