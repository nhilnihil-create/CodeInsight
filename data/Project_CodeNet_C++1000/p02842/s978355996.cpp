#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	int x;
	cin >> n;
	x = n*100/108;
	bool posssible = true;
	bool stop = false;
	while(posssible && !stop){
		int price = x;
		price *= 108;
		price /= 100;
		if(price==n){
			stop = true;
			x--;
		}else if(price>n){
			posssible = false;
		}
		x++;
	}
	if (posssible){
		printf("%d\n", x);
	}else{
		printf(":(\n");
	}

}