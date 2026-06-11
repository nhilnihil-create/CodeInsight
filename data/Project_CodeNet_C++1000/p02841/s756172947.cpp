#include<bits/stdc++.h>
using namespace std;
int m1,d1,m2,d2;
const int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	scanf("%d%d%d%d",&m1,&d1,&m2,&d2);
	if(d1==month[m1])
		printf("%d\n",1);
	else
		printf("%d\n",0);
	return 0;
}