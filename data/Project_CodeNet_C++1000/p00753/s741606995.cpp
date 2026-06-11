#include <iostream>
#include <cmath>
using namespace std;

void make_list(int m, int *pl);
int count_prime(int m, int *pl);

int main(void){
	
	int n;
	int prime_list[246912];
	make_list(246912, prime_list);
	
/*	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			cout << prime_list[i*10+j] << " ";
		}
		cout << endl;
	}
*/	
	while(1){
		cin >> n;
		
		if(n <= 0){
			break;
		}
		
		cout << (count_prime(2 * n, prime_list) -
			count_prime(n, prime_list)) << endl;
		
	}
	
	return 0;
}

void make_list(int m, int *pl){
	for(int i=2;i<m;i++){
		*(pl+i) = 1;
	}
	
	for(int i=2;i<(int)sqrt(m);i++){
		if(*(pl+i) == 0){
			continue;
		}
		for(int j=i+1;j<m;j++){
			if(j % i == 0){
				*(pl+j) = 0;
			}
		}
	}
	
}

int count_prime(int m, int *pl){
	if(m == 1){
		return 0;
	}
	int ans = 0;
	
	for(int i=0;i<=m;i++){
		if(*(pl+i) == 1){
			ans ++;
		}
	}
	
	return ans;
}