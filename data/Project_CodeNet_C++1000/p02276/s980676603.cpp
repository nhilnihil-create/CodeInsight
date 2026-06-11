#include <iostream>

void swap(int& x, int& y)
{
	int tmp = x;
	x = y;
	y = tmp;
}

int partition(int* A, int p, int r)
{
	int key = A[r];
	int i = p - 1;
	for (int j=p; j<r; j++) {
		if (A[j] <= key) {
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i+1], A[r]);
	return i+1;
}
	

int main()
{
	int n;
	std::cin >> n;
	
	int *A = new int[n];
	for (int i=0; i<n; i++) std::cin >> A[i];
	
	int k = partition(A, 0, n-1);
	
	std::cout << A[0];
	for (int i=1; i<k; i++) std::cout << " " << A[i];
	std::cout << " [" << A[k] << "]";
	for (int i=k+1; i<n; i++) std::cout << " " << A[i];
	std::cout << std::endl;
	
	delete[] A;
	
	return 0;
}


