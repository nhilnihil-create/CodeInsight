#include<iostream>
#include<stdio.h>
using namespace std;

main() {

  string number;
  int  i,c = 0, num, sum;

  while(1){
    sum = 0;
    c = 0;
    cin >> number;
    
    if(number[0] == '0') break;

    for(i = 0; number[i] != '\0'; i++){

	c++;

    }

    for(i = 0; i < c; i++){

	num = number[i] - '0';
	sum += num;

	

      
    }
    printf("%d\n",sum);
     
  }

}