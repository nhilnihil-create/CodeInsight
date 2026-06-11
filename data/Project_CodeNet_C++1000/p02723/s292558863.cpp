#include <cstdio> 
#include <iostream>
#include<algorithm>
#include <cstring>

using namespace std;

int main(){
	char coffee[10];
	scanf("%s",coffee);
	if(coffee[2] == coffee[3] && coffee[4] == coffee[5]){
		printf("Yes");
	}else{
		printf("No");
	}
}