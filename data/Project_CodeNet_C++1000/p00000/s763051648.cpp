#include<iostream>
int main(){
	for(int i=1; i<=9; i++)
		for(int k=1; k<=9; k++)
			std::cout << i << 'x' << k <<'=' << i*k << std::endl;
	return 0;
}