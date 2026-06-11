#include<stdio.h>
#include<iostream>
using namespace std;
int main(void){
	int i,s;
	scanf("%d",&s);
	if(s >= 400 && s <= 599){
	        printf("8");
	}else if (s>=600 && s<= 799 ){
	       printf("7");
	}else if (s>=800 && s<= 999 ){
	       printf("6");
	}else if (s>=1000 && s<=1199 ){
	       printf("5");
	}else if (s>=1200 && s<= 1399 ){
	       printf("4");
	}else if (s>=1400 && s<= 1599 ){
	       printf("3");
	}else if (s>=1600 && s<= 1799 ){
	       printf("2");
	}else if (s>=1800 && s<= 1999 ){
	       printf("1");
	}
}
