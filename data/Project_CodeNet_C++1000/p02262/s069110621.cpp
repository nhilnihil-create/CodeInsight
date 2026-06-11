#include <iostream>
#include <cstdio>

long long cnt;

void insertionSort(int *a, int n, int g){
	int i,v,j;
	for(i=g; i<n; i++){
		v = a[i];
		j = i-g;
		while(j>=0 && a[j] > v){
			a[j+g] = a[j];
			j -= g;
			cnt++;
		}
		a[j+g] = v;
	}
}

void shellSort(int *a, int n){
	int *g;
	int i,j,m;
	j=1;
	m=0;
	while(j<=n){
		m++;
		j = 3*j + 1;
	}
	std::printf("%d\n",m);
	g = new int[m];
	g[0]=1;
	for(i=1; i<m; i++){
		g[i] = 3*g[i-1] + 1;
	}
	for(i=m-1; i>0; i--){
		std::printf("%d ", g[i]);
		insertionSort(a, n, g[i]);
	}
	std::printf("%d\n", g[0]);
	insertionSort(a, n, g[0]);
}



int main(){
	int N, i;
	int *a;
	std::scanf("%d", &N);
	a = new int[N];
	
	for (i=0; i<N; i++) std::scanf("%d", &a[i]);
	
	shellSort(a, N);
	
	std::printf("%d\n", cnt);
	for (i=0; i<N; i++) std::printf("%d\n", a[i]);

	return 0;
}