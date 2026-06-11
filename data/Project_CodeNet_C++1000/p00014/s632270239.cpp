#include<cstdio>
//#include<cmath>
 
//#include<iostream>
using namespace std;
 
int main(){
long d, x, S;

	while( scanf("%d" , &d)!= EOF){
		for(S=0, x=0; x<600; x+=d)	S+=(x*x);
 		printf("%d\n",S*d);
	}

    return 0;
}