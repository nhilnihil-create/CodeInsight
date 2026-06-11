#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;



int main(){

	int count = 0;
	int arr[250000];
	int N;

	while(1){
		count = 0;
		scanf("%d",&N);

		if(N == 0){
			return 0;
		}
		if(N == 1){
			count = 1;
			goto loop;
		}
		for(int i = 0; i < 2*N; i++){
			arr[i] = 1;
		}
		for(int i = 2; i < sqrt(2*N); i++){
			if(arr[i]){
				for(int j = 0; i * (j + 2) < 2*N; j++){
					arr[i *(j + 2)] = 0;
				}
			}
		}
		for(int i = 2; i < 2*N; i++){
			if(arr[i]){
				if(i > N){
					count++;
				}
			}
		}

	loop:
		printf("%d\n",count);
	}
}