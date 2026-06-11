#include <stdio.h>

#include <string.h>

int input[1001];

    

int q_sort(int start, int end){

	if(end == start) return 0; 	else{ 

		int p = start;

		for(int i = (start + 1); i < end + 1; i++){ 

			if(input[i] < input[p]){ 

				int temp = input[i]; 

				memmove(input + start + 1, input + start, (i - start)*sizeof(int));

				input[start] = temp;

				p++; 

			}

		}

		if(start != p) q_sort(start,p-1);

		if(end != p) q_sort(p+1,end); 

		return 0;

	}

}

int main(){

	int a, b, c, d;

	scanf("%d%d", &a, &b);

	c = 0;

	for(int i = 0; i < a; i++){

		scanf("%d", &input[i]);

	}

	q_sort(0,a-1);

	for(int i = 0; i < b; i++){

		c = c + input[i];

	}

	printf("%d",c);

	return 0;

}