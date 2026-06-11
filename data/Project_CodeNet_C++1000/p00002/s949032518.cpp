#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int a,b;
	while(scanf("%d %d",&a,&b) != EOF){
		int i = 0;
		a += b;
		while(a > 0){
			a /= 10;
            i++;
		}
		cout << i << endl;
	}
}