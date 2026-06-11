#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
#define PI 3.14159265
	
int main(void){
	int num;
	while(1){
		double ave=0,sd=0,data;
		cin>>num;
		if(num==0)
			break;
		for(int i=0;i<num;i++){
			cin>>data;
			sd += data*data;
			ave += data;
		}
		sd /= num;
		ave /= num;
		sd -= ave*ave;
		cout.precision(8);
		cout<<sqrt(sd)<<endl;
	}
	return 0;
}