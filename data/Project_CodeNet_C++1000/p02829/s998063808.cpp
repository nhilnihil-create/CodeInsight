#include<stdio.h>
int main()
{
	int angka1, angka2;
	scanf("%d %d", &angka1, &angka2);
	if (angka1==1 && angka2==2) printf("3\n");
	else if (angka1==3 && angka2==1) printf("2\n");
	else if (angka1==2 && angka2==3) printf("1\n");
	else if (angka1==1 && angka2==3) printf("2\n");
	else if (angka1==2 && angka2==1) printf("3\n");
	else if (angka1==3 && angka2==2) printf("1\n");
	return 0;
}