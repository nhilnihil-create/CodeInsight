#include <stdio.h>

int main(){
	int n;
	int min = 0, max = 0;
	double som = 0;
	scanf("%d", &n);
	
	int a[n];
	
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	
	for(int i = 0; i < n; i++){
		if(a[i] < min || min == 0)
			min = a[i];
		
		if(a[i] > max || max == 0)
			max = a[i];
		
		som += (double)a[i];
	}
	
	printf("%d %d %.0lf\n", min, max, som);
	return 0;
}