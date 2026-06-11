#include<iostream>

long long calc_sum(int n, int a[]){
	long long sum=0;
	for(int i=0; i<n; i++) {
		sum += a[i];
	}
	return sum;
}

int seek_answer(int n, int a[], int minmax[]){
	minmax[0] = a[0];
	minmax[1] = a[0];
	for(int i=1; i<n; i++) {
		if(minmax[0] > a[i]) {
			minmax[0] = a[i];
		}
		if(minmax[1] < a[i]) {
			minmax[1] = a[i];
		}
	}
}


int main()
{
	int n;
	std::cin >> n;
	int a[n];
	for(int i=0; i<n; i++) {
		std::cin >> a[i];
	}
	long long sum;
	int minmax[2]; 
	sum = calc_sum(n, a);
	seek_answer(n, a, minmax);
	std::cout << minmax[0] << " " << minmax[1] << " " << sum << std::endl;

	return 0;
}