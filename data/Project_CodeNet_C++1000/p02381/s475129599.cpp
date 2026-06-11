#include<stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

int main(){
	
	double n, s[1000], data, x = 0, m, y = 0;
	
	while(1){
		
		x = 0;
		y = 0;
		
		cin >> n;
		if(n == 0) break;
		
		for(int i = 0; i < n; ++i){
			cin >> s[i];
			x += s[i];
		}
		
		m = x/n;
		
		for(int i = 0; i < n; ++i){
			y += (s[i] - m) * (s[i] - m);
		}
		
		printf("%f\n",sqrt(y/n));
	}
		
		return 0;
}