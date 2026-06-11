#include<stdio.h>
void print_array(int a[], int n){
int i = 0;
    for(i = 0; i<n-1; i++)
        printf("%d\n",a[i]);
    printf("%d\n",a[i]);
}
int insertion_sort(int a[], int n, int g){
	int cnt =0;
	for(int i = g; i<n; i++){
		int v = a[i];
		int j = i-g;
		while(j>=0 && a[j]>v){
			a[j+g] = a[j];
			j = j-g;
			cnt++;
		}
		a[j+g] = v;
	}
	return cnt;
}
//shell sort: th gap: 3*i+1: 1,4,13
void shell_sort(int a[], int n){
	int cnt = 0;
	int m = 1;
	int g[n+1];
	int k[n+1];
	k[0] = 1;
	for(int i = 1; i<n; i++){
		if(3*k[i-1]+1>n) break;
		k[i] = k[i-1]*3+1;
		m++;
	}
	for(int i = 0; i<m; i++){
		g[i] = k[m-1-i];
	}
	for(int i = 0; i<m; i++)
		cnt+=insertion_sort(a, n,g[i]);
	printf("%d\n",m);
	for(int i = 0;i < m-1; i++) printf("%d ",g[i]);
	printf("%d\n",g[m-1]);
	printf("%d\n",cnt);
	print_array(a,n);
}
int main(){
	int n;
	scanf("%d",&n);
	int a[n+1];
	for(int i = 0; i<n; i++) scanf("%d",&a[i]); 
	shell_sort(a,n);
	
	return 0;
}
