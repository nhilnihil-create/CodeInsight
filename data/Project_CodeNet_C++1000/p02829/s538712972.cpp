#include<bits/stdc++.h>
using namespace std;
#define sf(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d%d",&a,&b)
#define pf printf
#define PI 3.1416
int main( )
{
	int a,b;
	sf2(a,b);
	
	if(a==1 && b==2) pf("%d\n",3);
	else if(a==2 && b==1) pf("%d\n",3);
	else if(a==2 && b==3) pf("%d\n",1);
	else if(a==3 && b==2) pf("%d\n",1);
	else pf("%d\n",2);
}