#include <cstdio> 
#include <iostream>
#include<algorithm>
#include <cstring>

using namespace std;

int main(){
	int coin;
	int happy = 0;
	scanf("%d",&coin);
	if(coin >= 500){
		happy += (coin / 500)*1000;
		coin %= 500;
	}
	if(coin >= 5){
		happy += (coin / 5)*5;
	}
	printf("%d",happy);
}