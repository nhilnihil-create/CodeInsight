#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int n,count,flag;
	while(1){
		count = 0;
		cin >> n;
		if(n == 0)break;
		else if(n == 1){
			cout << 1 <<endl;
			continue;
		}
		else if(n%2 == 0){
			for(int i = n+1;i < n*2;i+=2){
				flag = 0;
				for(int j = 3;j <= sqrt(i);j+=2){
					if(i%j == 0){
						flag = 1;
						break;
					}
				}
				if(flag == 0)count++;
			}
		}
		else if(n%2 == 1){
			for(int i = n+2;i < n*2;i+=2){
				flag = 0;
				for(int j = 3;j <= sqrt(i);j+=2){
					if(i%j == 0){
						flag = 1;
						break;
					}
				}
				if(flag == 0)count++;
			}
		}
		cout << count <<endl;
	}
	return 0;
}