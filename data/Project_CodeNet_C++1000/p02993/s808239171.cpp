#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{  int n,m,i;
char a[4];
	while(~scanf("%s",&a))
	{  
	m=0;
	for(i=0;i<4;i++)
	if(a[i]==a[i+1])
    m=1;
	if(m==1)
	printf("Bad\n");
	else
	printf("Good\n");	
	
	}
	
}