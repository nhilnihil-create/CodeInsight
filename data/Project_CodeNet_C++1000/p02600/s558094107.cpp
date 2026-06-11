#include<bits/stdc++.h>
using namespace std;
int main()
{
	int num;
	scanf("%d",&num);
	switch((num-200)/200)
	{
		case 1:printf("8");break;
		case 2:printf("7");break;
		case 3:printf("6");break;
		case 4:printf("5");break;
		case 5:printf("4");break;
		case 6:printf("3");break;
		case 7:printf("2");break;
		case 8:printf("1");break;
	}
}